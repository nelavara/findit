/*Names: Jaron Bialecki & Evan Perry
* Date:  09-22-2020
*/
#include "Sniff.hpp"
//Constructor for the Sniff Class
Sniff::Sniff(int argc, char ** argv) {
    run(argc, argv);
    sortObjects();


}

//------------------------------------------------------------
/*
 * The work function creats a params object which parses the command line arguments and gets them
 * ready for the sniffer. We also populate the searchWords vector. Lastly we call oneDir() to start the process.
 */

void Sniff::run(int argc, char ** argv) {
    pms = new params(argc, argv);
    stringstream SniffWordsIn(pms->getSearchWords());
    string temp;
    while(getline(SniffWordsIn, temp, ' ')){
        sniffWords.push_back(temp);
    }
    char wcwd[PATH_MAX];
    char* npwd = getcwd(wcwd, sizeof(wcwd));
    cwd = string(npwd) + string(pms->getdirPath());
    char filePath[int(cwd.length())+1];
    strcpy(filePath, cwd.c_str());
    travel(filePath);
}


//------------------------------------------------------------
/*
 * oneDir first we construct a relative path based on our current working directory and then
 * append our search Directory location. Then we open the direction, lastly we read the entire contents
 * of the directory and get the Direntrys and the Stats ready for the FileIDmaker.
 */

void Sniff::travel(char* filePath) {
    //cout << filePath << endl;
    DIR *dir = opendir(filePath);
    if(errno!=0){
        throw Badsniff();
    }
    Direntry* tr;
    while((tr=(Direntry*)readdir(dir)) != NULL){
        //cout << "Travel: " << filePath << endl;
        if (tr->name()[0] != '.'){
            Direntry* temp;
            Stats* ts = new Stats();
            temp = tr;
            lstat(filePath, (Stats*)ts);
            Stats* temp1;
            temp1 = ts;
            cout << temp->name() << endl;
            FileIDmaker(temp, temp1, cwd);
           // if (temp->type() == 4){
               // travel(filePath);
          //  }

            }
        }
    closedir(dir);
}

//---------------------------------------------------------------------------------
/*
 * FileIDMaker makes the FileID objects. First we get the types read, make a tuple for easier passing and its cooler.
 * Next we create a new FileID, for FileIDs that are directories we push them onto the vector of subdirectories.
 * Files are only pushed on the files vector if they contain any of the search words. We delegate the
 * searching of the file to FileID. Lastly because in Program 3 we ignore all other files types.
 */
void Sniff::FileIDmaker(Direntry* temp, Stats* temp1, string cwd) {
    //cout << "=======================Entered FileID Maker============================"
    char filePath[int(cwd.length())+1];
    strcpy(filePath, cwd.c_str());
   //cout << "Directory: " << filePath << endl;
    if(temp->type()== 4){
        strcat(filePath, "/");
        strcat(filePath, temp->name());
        tuple <char*, char*, nlink_t, off_t, ino_t, bool, string, bool> dataContainer
                (filePath,temp->name(), temp1->links(), temp1->size(), temp->inode(), pms->getVerbose(), "Directory", pms->getCase());
        FileID* tempFID = new FileID(dataContainer);
        subdirectories.push_back(tempFID);


    }
    else if (temp->type() == 8){
        strcat(filePath, "/");
        strcat(filePath, temp->name());
        //cout << "Regular file: " << filePath << endl;
        tuple <char*, char*, nlink_t, off_t, ino_t, bool, string, bool> dataContainer
                (filePath,temp->name(), temp1->links(), temp1->size(), temp->inode(), pms->getVerbose(), "File", pms->getCase());
        FileID* tempFID = new FileID(dataContainer);

        if (tempFID->readFile(sniffWords)){
            files.push_back(tempFID);
        }
    }
    else if (temp->type() == 10){
        strcat(filePath, "/");
        strcat(filePath, temp->name());
       // cout << "Soft Link : " << filePath << endl;
        tuple <char*, char*, nlink_t, off_t, ino_t, bool, string, bool> dataContainer
                (filePath,temp->name(), temp1->links(), temp1->size(), temp->inode(), pms->getVerbose(), "Soft Link", pms->getCase());
        FileID* tempFID = new FileID(dataContainer);

        if (tempFID->readFile(sniffWords)){
            files.push_back(tempFID);
        }
    }
    else{
        cout << temp->type() << endl;
        cout << "File type not recognized.\n";
    }

}

//--------------------------------------------------------------
/*
 * Sort the files and directories by iNode.
 */

void Sniff::sortObjects() {
    for (int k= 0; k < int(subdirectories.size()); k++){
        allEntries.push_back(subdirectories[k]);
    }
    for (int k = 0; k < int(files.size()); k++){
        allEntries.push_back(files[k]);
    }
    CompareFileID cfid;
    sort(allEntries.begin(), allEntries.end(), cfid);

}

//-----------------------------------------------------------------------------
/*
 * Print function. We delegate printing to the FileID class.
 */
ostream& Sniff::print(ostream &out) {

    out << '\n';
    for (int k = 0; k < int(allEntries.size()); k++){
        allEntries[k]->print(out);
    }
    return out;
}