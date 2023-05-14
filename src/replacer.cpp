#include <iostream>
#include "string_reader.h"
#include <string>

/**
 * @brief sinの後に続く文字列がstrとマッチするかを示す。
 * マッチすれば、sinのポインタをその先のものへ移行する。
 */
static bool match_constant_token(string_reader& sin, std::string str){
    const int base = sin.current_pointer();
    for (const char c:str){
        if (sin.at_the_end() || sin.get() != c){
            sin.back_to(base);
            return false;
        }
    }
    return true;
}
void replace_all(string_reader& sin, std::ostream& sout){
    char c;
    while (sin.not_at_the_end()){
        sin >> c;
        if (c == '*') { sout << "\\cout"; }
        else if (c == 'i' && match_constant_token(sin, "nfinity")) { 
            sout << "\\infty";
        }
        else {sout << c;}
    }
}