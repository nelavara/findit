//
// Created by evanperry on 9/7/20.
//

#ifndef PROGRAM2_PARAMS_H
#define PROGRAM2_PARAMS_H
using namespace std;
#include <unistd.h>
#include <getopt.h>
//neeeded for including getopt_long https://linux.die.net/man/3/getopt_long
#include <ostream>
#include <string>
#include <iostream>
static struct option long_options[] = {
        {"dir", required_argument, 0, 0},
        {"verbose", optional_argument, 0, 0},
        {0,0,0,0}
};
class params{
    //ofstream
private:
    string searchWords;
    char** stringIn;
    int size;
    bool caseSensitivity = false; //- Do a case-insensitive search if this switch is present, case-sensitive is the default.
    bool recursiveSearch = false;  //-R do a recursive search if this switch is present, default is to search one directory.
    bool fileWriteOut = false; //-o pathname (optional): Open the named file and use it for output, default will be screen output.
    bool verbose = false; //--verbose print the name of every file that is opened.
    bool dir = false; //--dir or -d followed by a pathname. The app with start is search there.
    void parseCommands (int, char**);

public:
    params(int, char**); //constructor
    ~params() = default; //destructor
    ostream& print(ostream& out); //print function
};
inline ostream& operator << (ostream&out, params& pm) { return pm.print(out); }
#endif //PROGRAM2_PARAMS_H
