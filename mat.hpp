#include <iostream>
#include <string>

namespace ariel{ 
    std::string mat(int col, int row, char symbol_1, char symbol_2);
    void fill_mat(char** mat,int col, int row, char symbol_1, char symbol_2);
    bool check_input(int col, int row, char symbol_1, char symbol_2);
    std::string convert_mat(char** mat,int col, int row);
}