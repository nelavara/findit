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
}

ostream& Sniff::print(ostream &out) {
    for (int j = 0; j < int(sniffWords.size()); j++){
        out << sniffWords[j] << endl;
    }
    return out;
}
