//
// Created by evanperry on 9/7/20.
//
#include "params.h++"

params::params(int argc, char** argv) {
    //Here we define the options for getopt_long
    static struct option long_options[] = {
            {"dir", required_argument, 0, 1},
            {"verbose", no_argument, 0, 2},
            {0,no_argument,0,0}
    };
    int tester;
    for(;;){
        tester = getopt_long(argc, argv, "d:iRo:",long_options , &option_index);
        if (tester == -1){
            break;
        }
        switch(tester){
            case 'd':
                if ((optarg) && (searchWords.empty())){
                    searchWords = optarg;
                }
                else{
                    cout << "Either you have already specified a directory\n"
                            " or no argument was passed, try again.\n";
                    exit(1);
                }
                break;
            case 'i':
                caseSensitivity = true;
                break;
            case 'R':
                recursiveSearch = true;
                break;
            case 'o':
                fileWriteOut = true;
                if(optarg){
                    fileName = optarg;
                }
                break;
            case 2:
                verbose = true;
                break;
            case 1:
                if((optarg) && (searchWords.empty())){
                    searchWords = optarg;
                }
                else{
                    cout << "Either you have already specified a directory\n"
                            " or no argument was passed, try again.\n";
                    exit(1);
                }
                break;
        }
    }
    parseCommands(argc, argv); //this will more than likely be modified or eliminated as developed, here for testing purposes only.
    if (searchWords.empty()){
        cout << "You did not specifiy a directory!, try again!\n";
        exit(1);
    }
}

ostream & params::print(ostream &out) {
    //function stub

    return out;
}

void params::parseCommands(int size, char ** stringIn) {
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