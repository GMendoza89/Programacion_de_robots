#include<iostream>

using namespace std;


int main(int argc, char **argv){

    double A[3][3];
    double B[3][3];

    for(int i = 0; i < 3; i++ ){
        for(int j = 0; j < 3; j++){
            A[i][j] = i*3+j + 1;
            B[i][j] = i*3+j + 1;
        }
    }
    A[1][1] = 10;
    for(int i = 0; i < 3; i++ ){
        for(int j = 0; j < 3; j++){
            cout<< A[i][j]<<" ";
           
        }
        cout<<"\n";
    }

    return 0;

}


