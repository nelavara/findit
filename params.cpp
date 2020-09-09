//
// Created by evanperry on 9/7/20.
//
#include "params.h++"

params::params(int argc, char** argv) {
    //function stub
    //int test = getopt_long(argc, argv);
    //cout << test << endl;
    stringIn = argv;
    size = argc;
    parseCommands(argc, argv);

}

ostream & params::print(ostream &out) {
    //function stub

    return out;
}

void params::parseCommands(int, char **) {
    cout << "------------------------------------\n";
    cout << "command  " << stringIn[0] << '\n';

    for (int i=1; i< size; ++i) {
        if(stringIn[i][0] == '-')
            cout << "switch    " << stringIn[i] <<'\n';
        else if((stringIn[i][0] == '-' ) && (stringIn[i][1] == '-'))
            cout << "long option " << stringIn[i] << '\n';
        else
            cout << "argument  " << stringIn[i] << '\n';
    }
    cout << "--------------------------------------\n";
}