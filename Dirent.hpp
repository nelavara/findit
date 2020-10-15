#pragma once

#include <sys/dirent.h>

using namespace std;

class Dirent : public dirent {
    public:
        Dirent() = default;
        ~Dirent() = default;

        char*      name()  { return d_name; }
        ino_t      inode() { return d_ino; }
        __uint8_t  type()  { return d_type; }

        ostream& print(ostream& out);
};

inline ostream& operator << (ostream& out, Dirent& d) { return d.print(out); }