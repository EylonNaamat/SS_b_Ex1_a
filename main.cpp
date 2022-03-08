#include <iostream>
#include <string>
#include <vector>

int main(){

    std::vector< std::vector<char> > mat;
    mat.resize(5);
    for(int i = 0; i < 5; ++i){
        mat[i].resize(5);
    }
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            mat[i][j] = i;
        }
    }
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            std::cout << mat[i][j];
        }
        std::cout << "\n";
    }

std::vector< std::vector<int> > a;

  //m * n is the size of the matrix

    int m = 2, n = 4;
    //Grow rows by m
    a.resize(m);
    for(int i = 0 ; i < m ; ++i)
    {
        //Grow Columns by n
        a[i].resize(n);
    }
    //Now you have matrix m*n with default values

    //you can use the Matrix, now
    a[1][0]=1;
    a[1][1]=2;
    a[1][2]=3;
    a[1][3]=4;
    std::cout << a[1][0]; 
    std::cout << a[1][1];
    std::cout << a[1][2];
    std::cout << a[1][3];
    return 0;
}