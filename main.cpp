
/*Names: Jaron Bialecki & Evan Perry
* Date:  09-10-2020
*/
#include "Sniff.hpp"

int main (int argc, char** argv){

    //ofstream out(FN, ios_base::app);
    //params program2(argc, argv);
    //program2.print(cout);
    //out << program2;
    //out.close();
    Sniff sf (argc, argv);
    sf.print(cout);

    return 0;
}