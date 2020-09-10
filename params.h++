//
// Created by evanperry on 9/7/20.
//

#ifndef PROGRAM2_PARAMS_H
#define PROGRAM2_PARAMS_H
using namespace std;
#include <unistd.h>
#include <getopt.h>
//needed for including getopt_long https://linux.die.net/man/3/getopt_long
//https://linux.die.net/man/3/getopt_long
#include <ostream>
#include <string>
#include <iostream>
#include <fstream>

class params{
private:
    string searchWords; //search term, for now program can not do search terms with spaces.
    string directoryPath; //directory to start search at.
    bool caseSensitivity = false; //- Do a case-insensitive search if this switch is present, case-sensitive is the default.
    bool recursiveSearch = false;  //-R do a recursive search if this switch is present, default is to search one directory.
    bool fileWriteOut = false; //-o pathname (optional): Open the named file and use it for output, default will be screen output.
    bool verbose = false; //--verbose print the name of every file that is opened.
    string fileName; //this is where fileName to output too, used by -o
    string command; //the command, needed for print function as part of assignment constraints.

public:
    params(int, char**); //constructor
    ~params() = default; //destructor
    ostream& print(ostream& out); //print function
};
inline ostream& operator << (ostream&out, params& pm) { return pm.print(out); }
#endif //PROGRAM2_PARAMS_H
