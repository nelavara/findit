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
    const char* command = stringIn [0]; //not sure if this needs be const or not refer
    //to https://www.gnu.org/software/libc/manual/html_node/Getopt-Long-Options.html
    cout << "command   " << command << '\n';
    string smallSwitch; //string to hold small switch
    string largeSwitch; //string to hold verbose switch, or long option
    string argument;   //this is the argument that goes with any string we will need to deal with it if empty, but for now ignore
    string largeArgument; //also an argument, used for now to go with largeSwitch
    bool ss = false; //small switch boolean
    bool ls = false; //large switch boolean

    for (int i=1; i< size; ++i) {
        if(stringIn[i][0] == '-' && stringIn[i][1] != '-'){
            ss = true;
            ls = false;
            smallSwitch.append(stringIn[i]);
        }

        else if((stringIn[i][0] == '-' ) && (stringIn[i][1] == '-')){
            ss = false;
            ls = true;
            largeSwitch.append(stringIn[i]);
        }
        else{
            if (ss){
                argument.append(stringIn[i]);
            }
            if (ls){
                largeArgument.append(stringIn[i]);
            }
        }

    }
    cout << "switch    " << smallSwitch <<'\n';
    cout << "verbose    " << largeSwitch <<'\n';
    if (argument.empty()){
        cout << "argument  " << largeArgument << '\n';
    }
    else if (largeArgument.empty()){
        cout << "argument  " << argument << '\n';
    }
    else{
        cout << "argument  " << argument << '\n';
        cout << "argument  " << largeArgument << '\n';
    }


    cout << "--------------------------------------\n";
}