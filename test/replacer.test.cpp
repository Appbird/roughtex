#include "../include/acutest.h"
#include <sstream>
#include "../src/replacer.h"
using namespace std;
// テスト関数は(void) -> void型でなくてはならない
void ts_cdot(){
    istringstream sin{"a * b"};
    ostringstream sout;
    replace_all(sin, sout);
    // actualの値を表示したい
    TEST_CHECK_(sout.str() == "a \\cout b", "OUT: %s;", sout.str().c_str());
}

// 最後に{名前,関数ポインタ}対を列挙する必要あり
TEST_LIST = {
    {"cdot", ts_cdot}
};