/*Names: Jaron Bialecki & Evan Perry
* Date:  09-20-2020
*/
#pragma once
#include "Direntry.hpp"
#include <regex>

class FileID{
private:
    char* fileName;
    char* filePath;
    string fileType;
    ino_t iNodeNum;
    vector<string> sniffWords;
    void sniffWordmaker(string);
    int numOfLinks;
    int sizeofFile;
    bool verboseState;
public:
    FileID(tuple <char*, char*, nlink_t, off_t, ino_t, bool, string>);
    ~FileID() = default;
    ostream& print (ostream& out);
    bool readFile(vector<string>&);
};
inline ostream& operator << (ostream& out, FileID& fid) { return fid.print(out); }