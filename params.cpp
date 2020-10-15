#include "Params.hpp"

Params::
Params(int argc, char* argv[]) {
    int    s;
    string argName;

    pathname = nullptr;
    dirPath = " ";
    commands = " ";
    recursive = false;
    verbose = false;
    caseSens = false;
    output = false;

    for(int i = 0; i < argc; ++i) {
        argName = string(argv[i]);
        commands.append(argName + " ");
        cmdlne.push_back(argName);

        if(isalnum(argName[0]) && (i > 0 && cmdlne[i-1][0] != '-') ) {
            searchWords.append(argName.substr(0, s-1) + " ");
        }
    }
    
    processCL(argc, argv);
    if(output) writeToFile();
}

//-------------------------------------------------------------
void Params::
processCL(int argc, char* argv[]) {
    int p;

    for(;;) {
        p = getopt_long(argc, argv, "d:iRo:", long_options, 0);
     
        if(p == -1) break;
 
        switch(p) {
            case 'd': searchDir(); break;
            case 'i': caseSens = true; break;
            case 'R': recursive = true; break;
            case 'o': setFileName(); break;
            case  2:  verbose = true; break;
            case '?': 
            default:  usage(4); break;
        }

        if(dirPath.empty()) usage(3);
    }
}

//-------------------------------------------------------------
void Params::
searchDir() {
    if(invalidOpt() && dirPath.empty()) usage(1);

    string argName = string(optarg);

    for (int k = 0; k < argName.length(); k++){
        if(isspace(optarg[k])) usage(1);
    }

    dirPath = argName;
}

//-------------------------------------------------------------
void Params::
usage(const int err) {
    if (err == 1)
        cerr << "Either you have already specified a directory\n"
                " or no argument was passed, try again.\n";
    else if(err == 2)
        cerr << "You did not enter a file name, try again later.\n";
    else if (err == 3)
        cerr << "You did not specify a directory!, try again!\n";  
    else
        cerr << "Unrecognized argument or switch, try again.\n";

    cerr << "Proper usage: command options [-i][-R][-o][--verbose] --dir or -d /pathname \"Search Terms\"\n";

    exit(1);
}

//-------------------------------------------------------------
ostream& Params:: 
print(ostream& out) {
    string ver = verbose ? "Yes" : "No";
    string cas = caseSens ? "Yes" : "No";
    string re = recursive ? "Yes" : "No";
    string op = output ? string(pathname) : "No File";

    out << "Command: " << commands << '\n'
        << "Verbose? " << ver << '\n'
        << "Case Insensitive? " << cas << '\n'
        << "Output File Name: " << op << '\n'
        << "Directory: " << dirPath << '\n';  // May need to be changed

    return out;
}
