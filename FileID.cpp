#include "FileID.hpp"

ostream& FileID::
print(ostream& out) {
    out << "iNode No: " << iNodeNum << '\n';
    out << "Relative Path: " << relPath << '\n';
    out << "File Name: " << fileName << '\n';
    out << "Sniffwords: ";

    for(string snwrd : sniffWords) 
        out << snwrd << ' ';
    out << '\n';

    return out;
}