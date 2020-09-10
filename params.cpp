//
// Created by evanperry on 9/7/20.
//
#include "params.h++"

params::params(int argc, char** argv) {
    for (int j =0; j < argc; j++){
        command.append(argv[j]);
        if (j < argc){
            command.append(" ");
        }
    }
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
    if (searchWords.empty()){
        cout << "You did not specifiy a directory!, try again!\n";
        exit(1);
    }
}

ostream& params::print(ostream &out) {
    if (fileWriteOut){
        //open and write file.
        ofstream outFile;
        outFile.open(fileName, ios_base::app);
        if(outFile.is_open()){
            outFile << "Command: " << command << '\n';
            out << "Command: " << command << '\n';
            outFile << "Verbose? ";
            out << "Verbose? ";
            if (verbose){
                outFile << "Yes" << '\n';
                out << "Yes" << '\n';
            }
            else if (!verbose){
                outFile << "No" << '\n';
                out << "No" << '\n';
            }
            outFile << "Case insensitive? ";
            out << "Case insensitive? ";
            if (recursiveSearch){
                outFile << "Yes" << '\n';
                out << "Yes" << '\n';
            }
            else if (!recursiveSearch){
                outFile << "No" << '\n';
                out << "No" << '\n';
            }
            outFile << "Output file name: " << fileName << '\n';
            out << "Output file name: " << fileName << '\n';
            outFile << "Directory: " << searchWords << '\n';
            out << "Directory: " << searchWords << '\n';
        }
        outFile.close();
    }
    else{
        out << "Command: " << command << '\n';
        out << "Verbose? ";
        if (verbose){
            out << "Yes" << '\n';
        }
        else if (!verbose){
            out << "No" << '\n';
        }
        out << "Case insensitive? ";
        if (recursiveSearch){
            out << "Yes" << '\n';
        }
        else if (!recursiveSearch){
            out << "No" << '\n';
        }
        out << "No output file specified." << '\n';
        out << "Directory: " << searchWords << '\n';
    }

    return out;
}