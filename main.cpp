
/*Names: Jaron Bialecki & Evan Perry
* Date:  09-10-2020
*/
#include "Sniff.hpp"

int main (int argc, char** argv){

    ofstream out(FN, ios_base::app);
    fbanner(out);
    fbanner (cout);
    Sniff program3 (argc, argv);
    program3.print(cout);
    out << program3;
    out.close();
    bye();


    return 0;
}