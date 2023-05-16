#include <iostream>
#include "string_reader.h"
#include <map>

#include <iterator>
/**
 * @brief sinの後に続く文字列がstrとマッチするかを示す。
 * マッチすれば、sinのポインタをその先のものへ移行する。
 */
static inline bool match_constant_token(const char c, string_reader& sin, std::string str){
    assert(c == str.at(0));
    const int base = sin.current_pointer();
    for (std::string::iterator i = str.begin() + 1; i != str.end(); i++){
        if (sin.at_the_end() || sin.get() != *i){
            sin.back_to(base);
            return false;
        }
    }
    return true;
}
constexpr int MAX_TOKEN_SIZE = 20;
struct ConstantTokenPair{
    char before[MAX_TOKEN_SIZE];
    char after[MAX_TOKEN_SIZE];
};
using ConstantTokenMap = std::multimap<char, ConstantTokenPair>;

ConstantTokenMap get_ConstantTokenList(){
    ConstantTokenMap token_map;
    ConstantTokenPair pairs[] = {
        {"*", "\\cout"},
        {"infinity", "\\infty"},
        {"...", "\\cdots"},  
        {"{", "\\{"},  
        {"}", "\\}"},  
    };
    for (const ConstantTokenPair& branch : pairs){
        token_map.insert(std::make_pair(branch.before[0], branch));
    }
    return token_map;
}

void replace_all(string_reader& sin, std::ostream& sout){
    ConstantTokenMap constant_token_map = get_ConstantTokenList();
    char c;
    while (sin.not_at_the_end()){
        sin >> c;
        const auto token_matchers = constant_token_map.equal_range(c);
        // 対応するmatcherが見つからなかった時、文字をそのまま流す。
        if (token_matchers.first == token_matchers.second) { sout <<  c; }
        for (auto iter = token_matchers.first; iter != token_matchers.second; iter++){
            const ConstantTokenPair& branch = iter->second;
            if (match_constant_token(c, sin, branch.before)) { sout << branch.after; }
        }
    }
}