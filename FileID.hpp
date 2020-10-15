#pragma once

#include <iostream>
#include <vector>
#include "Dirent.hpp"
#include "Stats.hpp"

using namespace std;

class FileID {
    private:
        ino_t     iNodeNum;
        string    relPath;
        string    fileName;
        Dirent*   dnt;
        Stats     sts;
        vector<string> sniffWords;

    public:
        FileID(Dirent* d, Stats s, string path)
                : iNodeNum(s.inode()), fileName(d->name()), dnt(d), sts(s), relPath(path) {}
        FileID() = default;
        ~FileID() = default;

        bool swrdEmpty() { return sniffWords.empty(); }

        void insertSniff(string word) {
            auto it = find(sniffWords.begin(), sniffWords.end(), word);
            if(it == sniffWords.end()) sniffWords.push_back(word);
        }

        ostream& print(ostream& out);
};

inline ostream& operator << (ostream& out, FileID& fid) { return fid.print(out); }