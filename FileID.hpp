/*Names: Jaron Bialecki & Evan Perry
* Date:  09-20-2020
*/
#pragma once
#include "Direntry.hpp"

class FileID{
private:
    char* fileName;
    char* filePath;
    string fileType;
    ino_t iNodeNum;
    vector<string> sniffWords;
    vector<string> inComingSniff;
    void sniffWordmaker();
    int numOfLinks;
    int sizeofFile;
    bool verboseState;
public:
    FileID(tuple <char*, char*, nlink_t, off_t, ino_t, vector<string>, bool, string>);
    ~FileID() = default;
    ostream& print (ostream& out);
    void readFile();
};
inline ostream& operator << (ostream& out, FileID& fid) { return fid.print(out); }