/*Names: Jaron Bialecki & Evan Perry
* Date:  09-20-2020
*/
#include "FileID.hpp"

FileID::FileID(char*, unsigned short int, ino_t) {
    Direntry dey;
    // Stats st;
    fileName = dey.name();
    fileType = dey.type();
    iNodeNum = dey.inode();
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