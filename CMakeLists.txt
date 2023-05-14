cmake_minimum_required(VERSION 3.1)
project(RougTeX)
add_executable(main                 ./src/main.cpp ./src/replacer.cpp)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-long-long -pedantic -std=c++17")

enable_testing()
add_executable(test_using_acutest   ./test/test_using_acutest.test.cpp)
add_executable(test_replacer        ./test/replacer.test.cpp ./src/replacer.cpp)
add_executable(test_string_reader   ./test/string_reader.test.cpp)

add_test(NAME replacer COMMAND test_replacer)
add_test(NAME string_reader COMMAND test_string_reader)
add_test(NAME test_using_acutest COMMAND test_using_acutest)