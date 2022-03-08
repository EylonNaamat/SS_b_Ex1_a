#include <iostream>
#include <string>
#include "mat.hpp"
#include <stdexcept>
#include <typeinfo>


bool ariel::check_input(int col, int row, char symbol_1, char symbol_2){
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
    return true;

}

std::string ariel::mat(int col, int row, char symbol_1, char symbol_2){
    std::string ans = "";
    bool flag = check_input(col, row, symbol_1, symbol_2);
    if(flag){
        char** mat;
        mat = new char*[row];
        for(int i = 0; i < row; ++i){
            mat[i] = new char[col];
        }
        fill_mat(mat, col-1, row-1, symbol_1, symbol_2);
        ans = convert_mat(mat, col, row);
        for(int i = 0; i < row; ++i){
            delete (mat[i]);
        }
        delete[] mat;
    }else{
        std::cout << "need exception" << std::endl;
        ans = "";
    }
    return ans;
}

void ariel::fill_mat(char** mat,int col, int row, char symbol_1, char symbol_2){
    int top = 0;
    int down = row;
    int left = 0;
    int right = col;
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
}

std::string ariel::convert_mat(char** mat,int col, int row){
    std::string ans = "";
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            ans += mat[i][j];
        }
        ans += "\n";
    }
    return ans;
}


