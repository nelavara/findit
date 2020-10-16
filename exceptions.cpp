#include "exceptions.hpp"
//
// Created by evanperry on 10/3/20.
//
ostream & Badsniff::print(ostream &out) {
    if (whichErr == 0){
        out << "Something went wrong, check your spelling, perhaps the folder path you"<<
            " specified does not exist. Try again later!";
    }
    else if (whichErr == 1){
        out << "Either you have already specified a directory\n"
                " or no argument was passed, try again.\n";
    }
    else if (whichErr == 2){
        out << "You did not enter a file name, try again later.\n";
    }
    else if (whichErr == 3){
        out << "You did not specify a directory!, try again!\n";
    }
    else{
        out << "Unrecognized argument or switch, try again.\n";
    }
    out << "Proper usage: command options [-i][-R][-o][--verbose] --dir or -d /pathname \"Search Terms\"\n";
    return (out);
}