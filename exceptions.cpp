#include "exceptions.hpp"
//
// Created by evanperry on 10/3/20.
//
ostream & Badsniff::print(ostream &out) {
    out << "Something went wrong, check your spelling, perhaps the folder path you"<<
    " specified does not exist. Try again later!";
    return (out);
}
