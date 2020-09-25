/*Names: Jaron Bialecki & Evan Perry
* Date:  09-20-2020
*/
#pragma once
#include <dirent.h>
#include "Stats.hpp"


class Direntry : public dirent{
public:
    Direntry() = default;
    ~Direntry() = default;
    char* name() { return(d_name); }
    ino_t inode() { return(d_ino); }
    unsigned short int type() {return(d_type);}
    ostream& print (ostream& out) {out << "Name: " << name() <<
                                   '\n' << "Inode: " << inode()
                                   << '\n' << "Type: "<< type() << '\n';
        return out;}
};
inline ostream& operator << (ostream& out, Direntry& dy) { return dy.print(out); }