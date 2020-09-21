/*Names: Jaron Bialecki & Evan Perry
* Date:  09-20-2020
*/
#pragma once
#include "Direntry.hpp"

class FileID{
private:
    char* fileName;
    unsigned short int fileType;
    int iNodeNum;
    vector<string> sniffWords;
public:
    ostream& print (ostream&);
};
inline ostream& operator << (ostream& out, FileID& fid) { return fid.print(out); }