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
    char char_array[int(cwd.length())+1];
    strcpy(char_array, cwd.c_str());
    opendir(char_array);
    DIR *dir = opendir(char_array);
    Direntry* tr;
    cerr << char_array << '\n';
    while((tr=(Direntry*)readdir(dir)) != NULL){
        if (tr->name()[0] != '.' && tr->name()[1] != '.'){
            tr->print(cout);
            Stats* ts;
            lstat(char_array, ts=(Stats*)&tr);
            ts->print(cout);
        }
    }
    closedir(dir);

}

ostream& Sniff::print(ostream &out) {
    for (int j = 0; j < int(sniffWords.size()); j++){
        out << sniffWords[j] << '\t';
    }
    out << '\n';
    return out;
}
