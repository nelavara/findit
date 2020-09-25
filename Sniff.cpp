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
    char wcwd[PATH_MAX];
    char* npwd = getcwd(wcwd, sizeof(wcwd));
    cwd = string(npwd) + string(pms->getdirPath());
    char char_array[int(cwd.length())+1];
    strcpy(char_array, cwd.c_str());
    opendir(char_array);
    DIR *dir = opendir(char_array);
    Direntry* tr;
    while((tr=(Direntry*)readdir(dir)) != NULL){
        tr->print(cout);
    }
    //Direntry().print(cout);


    //int j = lstat(char_array, new Stats);
    //cout << j << endl;

}

ostream& Sniff::print(ostream &out) {
    for (int j = 0; j < int(sniffWords.size()); j++){
        out << sniffWords[j] << endl;
    }
    return out;
}
