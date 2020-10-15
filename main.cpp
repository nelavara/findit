#include <iostream>
#include "Sniff.hpp"

int main(int argc, char* argv[]) {
    Sniff sn(argc, argv);

    cout << sn << '\n';

    return 0;
}