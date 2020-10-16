/*Names: Jaron Bialecki & Evan Perry
* Date:  09-22-2020
*/
#include "Sniff.hpp"
//Constructor for the Sniff Class
Sniff::Sniff(int argc, char ** argv) : pms(argc, argv){
    run(argc, argv);
    sortObjects();


}

//------------------------------------------------------------
/*
 * The work function creats a params object which parses the command line arguments and gets them
 * ready for the sniffer. We also populate the searchWords vector. Lastly we call travel() to start the process.
 * but just before we call travel we set the current working directory and pass a char array of the path
 * and a string contained the current working directory.
 */

void Sniff::run(int argc, char ** argv) {
    stringstream SniffWordsIn(pms.getSearchWords());
    string temp;
    while(getline(SniffWordsIn, temp, ' ')){
        sniffWords.push_back(temp);
    }
    char wcwd[PATH_MAX];
    char* npwd = getcwd(wcwd, sizeof(wcwd));
    cwd = string(npwd) + string(pms.getdirPath());
    char filePath[int(cwd.length())+1];
    strcpy(filePath, cwd.c_str());
    string tcwd = cwd;
    travel(filePath, tcwd);
}


//------------------------------------------------------------
/*
 * travel takes a file path and a string of the current working directory.
 * Then we open the direction, lastly we read the entire contents
 * of the directory and get the Direntrys and the Stats ready for the FileIDmaker.
 */

void Sniff::travel(char* filePath, string tcwd) {
    DIR *dir = opendir(filePath);
    if(errno!=0){
        cout << filePath << endl;
        throw Badsniff();
    }
    Direntry* tr;
    while((tr=(Direntry*)readdir(dir)) != NULL){
        if (tr->name()[0] != '.'){
            Direntry* temp;
            Stats* ts = new Stats();
            temp = tr;
            lstat(filePath, (Stats*)ts);
            Stats* temp1;
            temp1 = ts;
            FileIDmaker(temp, temp1, tcwd);

            }
        }
    closedir(dir);
}


//---------------------------------------------------------------------------------
/*
 * FileIDMaker makes the FileID objects. First we get the types read, make a tuple for easier passing and its cooler.
 * Next we create a new FileID, for FileIDs that are directories we push them onto the vector of subdirectories.
 * Files are only pushed on the files vector if they contain any of the search words. We delegate the
 * searching of the file to FileID. Lastly because in Program 3 we ignore all other files types. If
 * a directory is pass we will update the current working directory and call travel() to walk across
 * that directory.
 */
void Sniff::FileIDmaker(Direntry* temp, Stats* temp1, string tcwd) {
    char filePath[int(tcwd.length())+1];
    strcpy(filePath, tcwd.c_str());
    if(temp->type()== 4){
        strcat(filePath, "/");
        strcat(filePath, temp->name());
        tuple <char*, char*, nlink_t, off_t, ino_t, bool, string, bool> dataContainer
                (filePath,temp->name(), temp1->links(), temp1->size(), temp->inode(), pms.getVerbose(), "Directory", pms.getCase());
        FileID* tempFID = new FileID(dataContainer);
        subdirectories.push_back(tempFID);
        if (pms.getRecursive()){
            tcwd = tcwd + "/" + temp->name();
            travel(filePath, tcwd);
        }
    }
    else if (temp->type() == 8){
        strcat(filePath, "/");
        strcat(filePath, temp->name());
        tuple <char*, char*, nlink_t, off_t, ino_t, bool, string, bool> dataContainer
                (filePath,temp->name(), temp1->links(), temp1->size(), temp->inode(), pms.getVerbose(), "File", pms.getCase());
        FileID* tempFID = new FileID(dataContainer);

        if (tempFID->readFile(sniffWords)){
            files.push_back(tempFID);
        }
    }
    else if (temp->type() == 10){
        strcat(filePath, "/");
        strcat(filePath, temp->name());
        tuple <char*, char*, nlink_t, off_t, ino_t, bool, string, bool> dataContainer
                (filePath,temp->name(), temp1->links(), temp1->size(), temp->inode(), pms.getVerbose(), "Soft Link", pms.getCase());
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
