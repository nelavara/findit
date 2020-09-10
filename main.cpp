//
// Created by evanperry on 9/7/20.
//
#include "params.h++"

int main (int argc, char** argv){

    params program2(argc, argv);
    program2.print(cout);


    return 0;
}


/*int main(int argc, char** argv) {
    ofstream out(FN, ios_base::app);
    helloShell hello(argc, argv);

    cout << hello << '\n';
    out << hello << '\n';

    out.close();

    return 0;
}
*/