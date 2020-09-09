//
// Created by evanperry on 9/7/20.
//
#include "params.h++"

params::params(int argc, char** argv) {
    //function stub
    int test = getopt_long(argc, argv);
    cout << test << endl;

}

ostream & params::print(ostream &out) {
    //function stub

    return out;
}
