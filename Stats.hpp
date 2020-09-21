/*Names: Jaron Bialecki & Evan Perry
* Date:  09-20-2020
*/
#pragma once
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
//https://linux.die.net/man/2/stat
#include "params.hpp"

class Stats : public stat {
public:
    Stats () = default;
    ~Stats() = default;
    ostream& print (ostream&) {out << "Inode: " << inode() <<
                                '\n' << "Links: " << links()
                                << '\n' << "Size: "<< size() << '\n';
                                  return out;}
    int inode() {return (st_ino);}
    int size() {return (st_size);}
    int links() {return (st_nlink);}
};
inline ostream& operator << (ostream& out, Stats& sts) { return sts.print(out); }