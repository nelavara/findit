/*Names: Jaron Bialecki & Evan Perry
* Date:  09-20-2020
*/
#pragma once
#include <dirent.h>

class Direntry : dirent{
public:
    Direntry() = default;
    ~Direntry() = default;
    char* name() { return(d_name); }
    ino_t inode() { return(d_ino); }
    unsigned short int type() {return(d_reclen);}
    ostream& print (ostream& );
};
inline ostream& operator << (ostream& out, Direntry& dy) { return dy.print(out); }