//
// Created by evanperry on 10/3/20.
//
#include "tools.hpp"
#pragma once

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