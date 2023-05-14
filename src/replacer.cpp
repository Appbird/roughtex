#include <iostream>
#include "string_reader.h"
void replace_all(string_reader& sin, std::ostream& sout){
    char c;
    while (sin.not_at_the_end()){
        sin >> c;
        if (c == '*') { sout << "\\cout"; }
        
        else {sout << c;}
    }
}