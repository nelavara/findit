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