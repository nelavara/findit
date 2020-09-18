/*Names: Jaron Bialecki & Evan Perry
* Date:  09-10-2020
*/
#include "params.hpp"

int main (int argc, char** argv){

    ofstream out(FN, ios_base::app);
    params program2(argc, argv);
    program2.print(cout);
    out << program2;
    out.close();


    return 0;
}