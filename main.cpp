#include <iostream>
#include <string>
#include "mat.hpp"

int main(){

    // std::string ans = ariel::mat(9,7,'$', '@');
    std::cout << ariel::mat(9, 7, '@', '-') << std::endl;

    return 0;
}