/*Names: Jaron Bialecki & Evan Perry
* Date:  09-20-2020
*/
#pragma once
#include "params.hpp"

//Stats wrapper class.
class Stats : public stat {
public:
    Stats () = default;
    ~Stats() = default;
    ostream& print (ostream& out) {out << "Inode: " << inode() <<
                                '\t' << "Links: " << links()
                                << '\t' << "Size: "<< size() << '\n';
                                  return out;}
    ino_t inode() {return (st_ino);}
    off_t size() {return (st_size);}
    nlink_t links() {return (st_nlink);}
};
inline ostream& operator << (ostream& out, Stats& sts) { return sts.print(out); }