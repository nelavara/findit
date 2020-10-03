//
// Created by evanperry on 10/3/20.
//
#include "tools.hpp"
#pragma once

class Badsniff {
public:
    Badsniff()=default;
    ~Badsniff()=default;
    ostream& print(ostream& out);
};
inline ostream& operator << (ostream& out, Badsniff& err) {return err.print(out);}