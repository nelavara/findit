/*Names: Jaron Bialecki & Evan Perry
* Date:  09-10-2020
*/
#include "params.hpp"
//--------------------------------------------------------
/*The constructor, takes argc and argv arguments from the main function
 * then delegates to processCL for parsing the command.*/
params::params(int argc, char** argv) {

    searchWords = "";
    directoryPath = nullptr;
    fileName = "";
    command = "";
    caseSensitivity = false;
    recursiveSearch = false;
    fileWriteOut = false;
    verbose = false;

    //We put the command into a string.
    for (int j = 0; j < argc; j++) {
        command.append(argv[j]);
        command.append(" ");
    }
    processCL(argc, argv);
}

//-------------------------------------------------------------------
/*getopt_long format is as follows argc, argv, short options, a ':' means options expected
 * long options structured passed in, and lastly a reference to the starting number which is
 * 0 in this case.*/
void params::processCL(int argc, char** argv){

    int tester;
    for(;;){
        tester = getopt_long(argc, argv, "d:iRo:",long_options , 0);
        if (tester == -1){
            break;
        }
        //Switch case statement is used to parse results from the getopt_long
        switch(tester){
            case 'd': directoryMaker(); break;
            case 'i': caseSensitivity = true; break;
            case 'R': recursiveSearch = true; break;
            case 'o': fileMaker(); break;
            case 2: verbose = true; break;
            case'?':
            default: usage(4); break;
        }
        if (searchWords.empty()){
            if (optind >= argc){
                usage(4);
            }
            if (argv[optind][0] != '-'){
                searchWords = string(argv[optind]);
            }
        }
    }
    if (directoryPath == nullptr){
        usage(3);
    }
    if (fileWriteOut){
        filePrint();
    }
}
//---------------------------------------------
/*Helper function for the making the directory variable.*/
void params::directoryMaker() {
    if (((!optarg) && (directoryPath != nullptr)) || (optarg[0] == '-')){
        usage(1);
    }
    for (int k = 0; k < int(string(optarg).size()); k++){
        if(isspace(optarg[k])){
            usage(1);
        }
    }
    directoryPath = optarg;
}

//-------------------------------------------------------
/*Helper function for making the fileName variable.*/
void params::fileMaker() {
    fileWriteOut = true;
    if(optarg){
        fileName = optarg;
        if (fileName[0] == '-'){
            usage(2);
        }
    }
}

//----------------------------------------------------------------
/*Usage function, used for error handling.*/

void params::usage(int whichErr) {
    cout << "The command you entered was: \n"
         << command << '\n';
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
    cout << "Proper usage: command options [-i][-R][-o][--verbose] --dir or -d /pathname \"Search Terms\"\n";
    exit(1);

}

//-----------------------------------------------------------------
/*Print function, checks if -o is true, if so creates file with string specified
 * if not it just prints out the results.*/
ostream& params::print(ostream &out) {
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

    out << "Search Term: " << searchWords << '\n'; //This is not required for submission only for testing.


    return out;
}

void params::filePrint() {
    //open and write file.
    ofstream outFile;
    outFile.open(fileName, ios_base::app);
    if (outFile.is_open()) {
        outFile << "Command: " << command << '\n';
        outFile << "Verbose? ";
        if (verbose) {
            outFile << "Yes" << '\n';
        } else if (!verbose) {
            outFile << "No" << '\n';
        }
        outFile << "Case insensitive? ";
        if (caseSensitivity) {
            outFile << "Yes" << '\n';
        } else if (!caseSensitivity) {
            outFile << "No" << '\n';
        }
        outFile << "Recursive Search: ";
        if (recursiveSearch) {
            outFile << "Yes" << '\n';
        } else if (!recursiveSearch) {
            outFile << "No" << '\n';
        }
        outFile << "Output file name: " << fileName << '\n';
        outFile << "Directory: " << directoryPath << '\n';
    }
    outFile << "------------------------------------------------------\n";
    outFile.close();
}