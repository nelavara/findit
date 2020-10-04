/*Names: Jaron Bialecki & Evan Perry
* Date:  09-20-2020
*/
#pragma once
#include "Direntry.hpp"
//File ID class holds the details of each entry parsed by the sniffer
//Files that do not contact sniff words are discarded.
class FileID {
private:
    friend struct CompareFileID;
    char* fileName;
    char* filePath;
    ino_t iNodeNum;
    int numOfLinks;
    int sizeofFile;
    bool verboseState;
    string fileType;
    vector<string> sniffWords;

    void sniffWordmaker(string);

public:
    FileID(tuple <char*, char*, nlink_t, off_t, ino_t, bool, string>);
    ~FileID() = default;
    ostream& print (ostream& out);
    bool readFile(vector<string>&);
    bool operator < (const FileID* b) { return iNodeNum < b->iNodeNum; }

};

inline ostream& operator << (ostream& out, FileID& fid) { return fid.print(out); }

struct CompareFileID {
    friend class FileID;
    bool operator()(const FileID* a, const FileID* b) {
        return a->iNodeNum < b->iNodeNum;
    }
};