#pragma once

#include <sys/stat.h>

using namespace std;

class Stats : public stat {
    public:
        Stats() = default;
        ~Stats() = default;

        ino_t   inode() { return st_ino; }
        off_t   size()  { return st_size; }
        nlink_t links() { return st_nlink; }

        ostream& print(ostream& out);
};

inline ostream& operator << (ostream& out, Stats& s) { return s.print(out); }