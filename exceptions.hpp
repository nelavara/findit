//
// Created by evanperry on 10/3/20.
//
#pragma once
#define FN "P4_PerBia.txt"

#include <getopt.h>
#include <ostream>
#include <string>
#include <tuple>
#include <functional>
#include <regex>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>

#include <cstdio>      // for NULL
#include <cstdlib>     // for malloc() and calloc()
#include <cstring>     // for time_t, time() and ctime()
#include <cmath>
#include <ctime>
#include <cctype>      // for isspace() and isdigit()
#include <cstdarg>     // for functions with variable # of args
#include <cerrno>

using namespace std;

class Badsniff {
    int whichErr;
public:
    Badsniff(int wE){
        whichErr =wE;
    }
    ~Badsniff()=default;
    ostream& print(ostream& out);
};
inline ostream& operator << (ostream& out, Badsniff& err) {return err.print(out);}