#include "acutest.h"
// テスト関数は(void) -> void型でなくてはならない
void test_of_test(){
    TEST_CHECK(1 + 1 == 2);
    TEST_CHECK(true == true);
}

// 最後に{名前,関数ポインタ}対を列挙する必要あり
TEST_LIST = {
    {"super_simple_case", test_of_test}
};