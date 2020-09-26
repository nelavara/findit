/*Names: Jaron Bialecki & Evan Perry
* Date:  09-20-2020
*/
#pragma once
#include "Direntry.hpp"

class FileID{
private:
    char* fileName;
    char* filePath;
    unsigned short int fileType;
    ino_t iNodeNum;
    vector<string> sniffWords;
    void sniffWordmaker(string);
    int numOfLinks;
public:
    FileID(char*, unsigned short int, ino_t, nlink_t, char*);
    ~FileID() = default;
    ostream& print (ostream& out);
};
inline ostream& operator << (ostream& out, FileID& fid) { return fid.print(out); }