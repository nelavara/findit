/*Names: Jaron Bialecki & Evan Perry
* Date:  09-20-2020
*/
#include "FileID.hpp"

FileID::FileID(tuple <char*, char*, nlink_t, off_t, ino_t, bool, string> dataContainer) {
    filePath = get<0>(dataContainer);
    fileName = get<1>(dataContainer);
    numOfLinks = get<2>(dataContainer);
    sizeofFile = get<3>(dataContainer);
    iNodeNum = get<4> (dataContainer);
    verboseState = get<5>(dataContainer);
    fileType = get<6>(dataContainer);
}

void FileID::sniffWordmaker(string inComing) {
    if (sniffWords.empty()){
        sniffWords.push_back(inComing);
    }
    else{
        for (int k = 0; k < int(sniffWords.size()); k++){
            bool found = false;
            for (int j =0 ; j < int(sniffWords.size()); j ++){
                if (sniffWords[j]==inComing){
                    found = true;
                    break;
                }
            }
            if (!found){
                sniffWords.push_back(inComing);
            }
        }
        }

}

bool FileID::readFile(vector<string>& tobeSniffed){
    string line;
    string test1= "\\b(";
    string test2 = ")([^ ]*)";
    ifstream readin;
    readin.open(filePath);
    bool foundone = false;
    bool anyWordfound = false;
    while(getline(readin, line)){
        foundone = false;
        istringstream iss (line);
        if(!iss) break;
        for (int k = 0; k < int(tobeSniffed.size()); k++){
            string regPattern = test1+tobeSniffed[k]+test2;
            smatch test;
            regex des (regPattern);
            while(regex_search(line,test,des)){
                for (string x:test) {
                    anyWordfound = true;
                    foundone = true;
                    sniffWordmaker(x);
                    break;
                }
                if (foundone) break;
            }
        }
    }
    readin.close();

    return anyWordfound;
}

ostream& FileID::print(ostream& out) {
    out << "------------FileID output------\n";
    out << "File Name: \t" << fileName << '\n';
    out << "File Type: \t" << fileType << '\n';
    out << "iNode Number: " << iNodeNum << '\n';
    out << "-------End of FileID output-----\n";
    for (int j = 0; j < int(sniffWords.size()); j++){
        out << sniffWords[j] << endl;
    }
    return out;
}