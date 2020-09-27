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
    vector<string> inComingSniff;
    void sniffWordmaker(string);
    int numOfLinks;
    int sizeofFile;
public:
    FileID(tuple <char*, char*, nlink_t, off_t, ino_t, vector<string>>);
    ~FileID() = default;
    ostream& print (ostream& out);
};
inline ostream& operator << (ostream& out, FileID& fid) { return fid.print(out); }