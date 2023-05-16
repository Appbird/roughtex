#include "../include/acutest.h"
#include <sstream>
#include "../src/string_reader.h"
#include "../src/replacer.h"
using namespace std;
void expect_from_to(std::string input, std::string expected_str) {
    string_reader sin{input};
    ostringstream sout;
    const string expected = expected_str;
    replace_all(sin, sout);
    TEST_CHECK_(sout.str() == expected, "OUT: \"%s\"", sout.str().c_str());
}

void ts_cdot(){
    expect_from_to("a * b", "a \\cout b");
}

void ts_infinity(){
    expect_from_to("a \\to infinity", "a \\to \\infty");
}

void ts_cdots(){
    expect_from_to("0 ... 1", "0 \\cdots 1");
}

// 最後に{名前,関数ポインタ}対を列挙する必要あり
TEST_LIST = {
    {"cdot", ts_cdot},
    {"infinity", ts_infinity},
    {"cdots", ts_cdots}
};