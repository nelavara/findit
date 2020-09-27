/*Names: Jaron Bialecki & Evan Perry
* Date:  09-22-2020
*/
#include "Sniff.hpp"
Sniff::Sniff(int argc, char ** argv) {
    //The directions in 4.1 do not make sense when params already gets the search words for you.
    work(argc, argv);
}

void Sniff::work(int argc, char ** argv) {
    pms = new params(argc, argv);
    stringstream SniffWordsIn(pms->getSearchWords());
    string temp;
    while(getline(SniffWordsIn, temp, ' ')){
        sniffWords.push_back(temp);
    }
    oneDir();
}

void Sniff::oneDir() {
    char wcwd[PATH_MAX];
    char* npwd = getcwd(wcwd, sizeof(wcwd));
    cwd = string(npwd) + string(pms->getdirPath());
    char filePath[int(cwd.length())+1];
    strcpy(filePath, cwd.c_str());
    opendir(filePath);
    DIR *dir = opendir(filePath);
    Direntry* tr;
    while((tr=(Direntry*)readdir(dir)) != NULL){
        if (tr->name()[0] != '.' && tr->name()[1] != '.'){
            Direntry* temp = new Direntry();
            temp = tr;
            Stats* ts;
            lstat(filePath, ts=(Stats*)&tr);
            Stats* temp1 = new Stats();
            temp1 = ts;
            FileIDmaker(temp, temp1, cwd);
        }
    }
    closedir(dir);
}

void Sniff::FileIDmaker(Direntry* temp, Stats* temp1, string cwd) {
    //temp->print(cout);
    //temp1->print(cout);

    char filePath[int(cwd.length())+1];
    strcpy(filePath, cwd.c_str());
    if(temp->type() == 4){
        strcat(filePath, "/");
        strcat(filePath, temp->name());
        tuple <char*, char*, nlink_t, off_t, ino_t, vector<string>, bool, string> dataContainer
        (filePath,temp->name(), temp1->links(), temp1->size(), temp->inode(), sniffWords, pms->getVerbose(), "Directory");
        FileID* tempFID = new FileID(dataContainer);
        subdirectories.push_back(tempFID);

    }
    else if (temp->type() == 8){
        cout << "File Found!\n";
        strcat(filePath, "/");
        strcat(filePath, temp->name());
        tuple <char*, char*, nlink_t, off_t, ino_t, vector<string>, bool, string> dataContainer
        (filePath,temp->name(), temp1->links(), temp1->size(), temp->inode(), sniffWords, pms->getVerbose(), "File");
        FileID* tempFID = new FileID(dataContainer);
        tempFID->print(cout);
        tempFID->readFile();

    }
    else{
        cout << "File type not recognized.\n";
    }

}

ostream& Sniff::print(ostream &out) {
    out << '\n';
    for (int k =0; k < int(subdirectories.size()); k++){
        subdirectories[k]->print(out);
    }
    return out;
}
