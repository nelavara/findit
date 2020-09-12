/*Names: Jaron Bialecki & Evan Perry
* Date:  09-10-2020
*/
#include "params.h++"
//--------------------------------------------------------
/*The constructor, takes argc and argv arguments from the main function
 * then uses getopt_long to process them. For now if there errors we stop processing here.*/
params::params(int argc, char** argv) {
     //We push all arguments into vector this allows for multiple words to be put into searchWords later
    for (int j =0; j < argc; j++){
        commandLine.push_back(argv[j]);
        command.append(argv[j]);
        command.append(" ");
    }
    //Here we define the options for getopt_long
    //Format of each long_option is as follows (name, argument?, flag?, value returned.
    static struct option long_options[] = {
            {"dir", required_argument, 0, 'd'},
            {"verbose", no_argument, 0, 2},
            {0,0,0,0}
    };
    int tester;
    /*getopt_long format is as follows argc, argv, short options, a ':' means options expected
     * long options structured passed in, and lastly a reference to the starting number which is
     * 0 in this case.*/
    for(;;){
        tester = getopt_long(argc, argv, "d:iRo:",long_options , 0);
        if (tester == -1){
            break;
        }
        if (argv[optind][0] != '-'){
            searchWords = string(argv[optind]);

        }
        //Switch case statement is used to parse results from the getopt_long
        switch(tester){
            case 'd':
                if ((optarg) && (directoryPath.empty())){
                    if (optarg[0] == '-'){
                        usage(1);
                    }
                    for (int k = 0; k < int(string(optarg).size()); k++){
                        if(isspace(optarg[k])){
                            usage(1);
                        }
                    }
                    directoryPath = optarg;
                }
                else{
                    usage(1);
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
                    if (fileName[0] == '-'){
                        usage(2);
                    }
                }
                break;
            case 2:
                verbose = true;
                break;
            case'?':
                usage(4);
                break;
            default:
                usage(4);
        }
    }
    if (directoryPath.empty()){
        usage(3);
    }
}

void params::usage(int whichErr) {
    if (whichErr == 1){
        cout << "Either you have already specified a directory\n"
                " or no argument was passed, try again.\n";
    }
    else if(whichErr == 2){
        cout << "You did not enter a file name, try again later.\n";
    }
    else if (whichErr == 3){
        cout << "You did not specify a directory!, try again!\n";
    }
    else{
        cout << "Unrecognized argument or switch, try again.\n";
    }
    cout << "Proper usage: command options [-i][-R][-o][--verbose] --dir or -d /pathname \"Search Tearms\"\n";
    exit(1);

}

//-----------------------------------------------------------------
/*Print function, checks if -o is true, if so creates file with string specified
 * if not it just prints out the results.*/
ostream& params::print(ostream &out) {
        //open and write file.
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
            if (caseSensitivity){
                out << "Yes" << '\n';
                outFile << "Yes" << '\n';
            }
            else if (!caseSensitivity){
                out << "No" << '\n';
                outFile << "No" << '\n';
            }
            out << "Recursive Search: ";
            outFile << "Recursive Search: ";
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
            outFile << "Directory: " << directoryPath << '\n';
            out << "Directory: " << directoryPath << '\n';
            }
        outFile << "------------------------------------------------------\n";
        out << "------------------------------------------------------\n";
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
        if (caseSensitivity){
            out << "Yes" << '\n';
        }
        else if (!caseSensitivity){
            out << "No" << '\n';
        }
        out << "Recursive Search: ";
        if (recursiveSearch){
            out << "Yes" << '\n';
        }
        else if (!recursiveSearch){
            out << "No" << '\n';
        }
        out << "No output file specified." << '\n';
        out << "Directory: " << directoryPath << '\n';
        out << "------------------------------------------------------\n";
    }
    out << "Search Term: " << searchWords << '\n'; //This is not required for submission only for testing.


    return out;
}