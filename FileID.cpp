/*Names: Jaron Bialecki & Evan Perry
* Date:  09-20-2020
*/
#include "FileID.hpp"

FileID::FileID(tuple <char*, char*, nlink_t, off_t, ino_t, vector<string>> dataContainer) {
    filePath = get<0>(dataContainer);
    fileName = get<1>(dataContainer);
    numOfLinks = get<2>(dataContainer);
    sizeofFile = get<3>(dataContainer);
    iNodeNum = get<4> (dataContainer);
    inComingSniff = get<5>(dataContainer);
}

void FileID::sniffWordmaker(string sniff) {
    if (sniffWords.empty()){
        sniffWords.push_back(sniff);
    }
    else{
        bool found = false;
        for (int j =0 ; j < int(sniffWords.size()); j ++){
            if (sniffWords[j]==sniff){
                found = true;
                break;
            }
        }
        if (found){
            sniffWords.push_back(sniff);
        }
    }
}

ostream& FileID::print(ostream& out) {
    out << "------------FileID output------\n";
    out << "File Name: \t" << fileName << '\n';
    out << "File Type: \t" << fileType << '\n';
    out << "iNode Number: " << iNodeNum << '\n';
    out << "-------End of FileID output-----\n";
    return out;
}