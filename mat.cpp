#include <iostream>
#include <string>
#include "mat.hpp"
#include <stdexcept>
#include <vector>


void ariel::check_input(int col, int row, char symbol_1, char symbol_2){
    if (col % 2 == 0 || row % 2 == 0){
        throw std::invalid_argument("Mat size is always odd");
    }
    if (symbol_1 == ' ' || symbol_1 == '\t' || symbol_1 == '\n' || symbol_1 == '\r'){
        throw std::invalid_argument("invalid symbol");
    }
    if (symbol_2 == ' ' || symbol_2 == '\t' || symbol_2 == '\n' || symbol_2 == '\r'){
        throw std::invalid_argument("invalid symbol");
    }
    if(row < 0 || col < 0){
        throw std::invalid_argument("you should only positive numbers");
    }
}

std::string ariel::mat(int col, int row, char symbol_1, char symbol_2){
    check_input(col, row, symbol_1, symbol_2);
    std::string ans;
    std::vector < std::vector<char>> mat(row, std::vector<char>(col));
        int top = 0;
    int down = row-1;
    int left = 0;
    int right = col-1;
    int flag = 0;
    char curr_symbol = symbol_1;
    
    while(top <= down && left <= right){
        if(flag % 2 == 0){
            curr_symbol = symbol_1;
        }else{
            curr_symbol = symbol_2;
        }

        for(int i = left; i <= right; ++i){
            mat[top][i] = curr_symbol;
        }
        ++top;
        for(int i = top; i <= down; ++i){
            mat[i][right] = curr_symbol;
        }
        --right;
        for(int i = right; i >= left; --i){
            mat[down][i] = curr_symbol;
        }
        --down;
        for(int i = down; i >= top; --i){
            mat[i][left] = curr_symbol;
        }
        ++left;
        ++flag;
    }
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            ans += mat[i][j];
        }
        ans += "\n";
    }
    return ans;
}



