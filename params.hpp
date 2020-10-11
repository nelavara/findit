/*Names: Jaron Bialecki & Evan Perry
* Date:  09-10-2020
*/
#pragma once
#include "exceptions.hpp"
constexpr static struct option long_options[] = {
        {"dir", required_argument, 0, 'd'},
        {"verbose", no_argument, 0, 2},
        {0,0,0,0}
};
class params{
private:
    friend class Sniff;
    //Here we define the options for getopt_long
    //Format of each long_option is as follows (name, argument?, flag?, value returned.

    string searchWords; //search term, for now program can not do search terms with spaces.
    char* directoryPath; //directory to start search at.
    string fileName; //this is where fileName to output too, used by -o
    string command; //the command, needed for print function as part of assignment constraints.
    bool caseSensitivity; //-i Do a case-insensitive search if this switch is present, case-sensitive is the default.
    bool recursiveSearch;  //-R do a recursive search if this switch is present, default is to search one directory.
    bool fileWriteOut; //-o pathname (optional): Open the named file and use it for output, default will be screen output.
    bool verbose; //--verbose print the name of every file that is opened.
    void processCL(int argc, char** argv);
    void usage (int);
    void directoryMaker();
    void fileMaker();
    void filePrint();
    string getSearchWords(){return searchWords;}
    char* getdirPath(){return directoryPath;}
    bool getVerbose () {return verbose;}
    bool getCase () {return caseSensitivity;}
    bool getRecursive () {return recursiveSearch;}
public:
    params(int, char**); //constructor
    ~params() = default; //destructor
    ostream& print(ostream& out); //print function
};
inline ostream& operator << (ostream& out, params& pm) { return pm.print(out); }
