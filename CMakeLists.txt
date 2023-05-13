cmake_minimum_required(VERSION 3.1)
project(RougTeX CXX)
add_executable(main ./src/main.cpp)
add_executable(test_using_acutest ./src/test_using_acutest.cpp)

enable_testing()

add_test(NAME test_using_acutest COMMAND test_using_acutest)