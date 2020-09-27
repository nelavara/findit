
/*Names: Jaron Bialecki & Evan Perry
* Date:  09-10-2020
*/
#include "Sniff.hpp"

int main (int argc, char** argv){

    ofstream out(FN, ios_base::app);
    //params program2(argc, argv);
    //program2.print(cout);
    //out << program2;
    //out.close();
    Sniff program3 (argc, argv);
    program3.print(cout);
    out << program3;
    out.close();


    return 0;
}