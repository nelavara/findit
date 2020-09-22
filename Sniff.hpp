/*Names: Jaron Bialecki & Evan Perry
* Date:  09-20-2020
*/
#pragma once
#inlcude "FileID.hpp"

class Sniff{
private:
    params pms;
    vector<string> sniffWords;
    vector<FileID> files;
    vector<FileID> subdirectories;
    string cwd = "./";
public:
    Sniff(int, char**);
    ~Sniff() = default;
    void oneDir();
    ostream& print(ostream& out);
    void word();
};
inline ostream& operator << (ostream& out, Sniff& sf) { return sf.print(out); }