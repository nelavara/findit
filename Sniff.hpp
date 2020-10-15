#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <dirent.h>
#include "FileID.hpp"
#include "Dirent.hpp"
#include "Stats.hpp"
#include "Params.hpp"
#include "Exception.hpp"

using namespace std;

class Sniff {
    private:
        string         currDirPath;
        Params         prm;
        vector<string> sniffWords;
        vector<FileID> files;

        void   oneDir();
        FileID oneFile(Dirent* fi, Stats sts, string path);

        bool validFile(Dirent* d) { 
            return d->type() == DT_DIR || d->type() == DT_REG;
        }

        void setPath(string& path, char* file) {
            path = currDirPath;
            path.push_back('/');
            path.append(file);
        }

    public:
        Sniff(int argc, char* argv[]);
        ~Sniff() = default;

        ostream& print(ostream& out);
};

inline ostream& operator << (ostream& out, Sniff& sn) { return sn.print(out); }
