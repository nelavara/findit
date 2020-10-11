/*Names: Jaron Bialecki & Evan Perry
* Date:  09-20-2020
*/
#pragma once
#include "FileID.hpp"
//Sniff class declaration.
class Sniff {
private:
    friend class params;
    params* pms;
    vector<string> sniffWords;
    vector<FileID*> files;
    vector<FileID*> subdirectories;
    vector<FileID*> allEntries;
    string cwd = "./";
    void run(int, char**);
    void travel(char*);
    void FileIDmaker(Direntry*, Stats*, string);
    void getDirectoryPath();
    void sortObjects();

public:
    Sniff(int, char**);
    ~Sniff() = default;
    ostream& print(ostream& out);
};

inline ostream& operator << (ostream& out, Sniff& sf) { return sf.print(out); }