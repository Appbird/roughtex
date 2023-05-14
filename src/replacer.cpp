#include <iostream>

void replace_all(std::istream& sin,std::ostream& sout){
    char c;
    sin >> std::noskipws;
    while (sin >> c){
        if (c == '*') { sout << "\\cout"; }
        else {sout << c;}
    }
}