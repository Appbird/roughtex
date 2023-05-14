#include "../include/acutest.h"
#include "../src/string_reader.h"
#include <string>

void ts_sr_proceed(){
    std::string target{"abcdef"};
    string_reader sr(target);
    std::string out = "";
    while(sr.not_at_the_end()){
        out += sr.get();
    }
    TEST_CHECK_(out == target, "OUT: %s", out.c_str());
}
void ts_sr_proceed_with_operator(){
    std::string target{"abcdef"};
    string_reader sr(target);
    std::string out = "";
    while(sr.not_at_the_end()){
        char c;
        sr >> c;
        out += c;
    }
    TEST_CHECK_(out == target, "OUT: %s", out.c_str());
}
void ts_sr_peek(){
    std::string target{"abcdef"};
    string_reader sr(target);
    std::string out = "";
    out += sr.get();
    out += sr.get();
    out += sr.get();
    out += sr.peek();
    out += sr.peek();
    TEST_CHECK_(out == "abcdd", "OUT: %s", out.c_str());
}
void ts_sr_back(){
    std::string target{"abcdef"};
    string_reader sr(target);
    std::string out = "";
    out += sr.get();
    out += sr.get();
    out += sr.get();
    out += sr.back();
    out += sr.back();
    TEST_CHECK_(out == "abccb", "OUT: %s", out.c_str());
}

void ts_sr_back_to(){
    std::string target{"123456"};
    string_reader sr(target);
    std::string out = "";
    out += sr.get();
    const int backup = sr.current_pointer();
    out += sr.get();
    out += sr.get();
    out += sr.get();
    sr.back_to(backup);
    out += sr.get();
    out += sr.get();
    out += sr.get();
    TEST_CHECK_(out == "1234234", "OUT: %s", out.c_str());
}

TEST_LIST = {
    {"proceed", ts_sr_proceed},
    {"proceed_with_>>", ts_sr_proceed_with_operator},
    {"peek", ts_sr_peek},
    {"back", ts_sr_back},
    {"current_pointer and back_to", ts_sr_back_to}
};