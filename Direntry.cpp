//
// Created by evanperry on 9/26/20.
//
#include "Direntry.hpp"

ostream & Direntry::print(ostream &out) {

    if(type()==4)
    {
        fileType = "Directory";
    }
    else if(type() == 8){
        fileType = "File";
    }
    else{
        fileType = "Unkown";
    }

    out << "Name: " << name() <<
        '\t' << "Inode: " << inode()
        << '\t' << "Type: "<< fileType << '\t';
    return out;
}