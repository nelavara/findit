/*Names: Jaron Bialecki & Evan Perry
* Date:  09-20-2020
*/
#include "FileID.hpp"

FileID::FileID(char* name, unsigned short int ft, ino_t nodeNum, nlink_t numLinks, char* fp) {
    fileName = name;
    fileType = ft;
    iNodeNum = nodeNum;
    numOfLinks = numLinks;
    filePath = fp;
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