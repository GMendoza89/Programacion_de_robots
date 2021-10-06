
/*
* Libreria de matrices
* Autor: Ing. Gustavo David Mendoza Pinto
* 
*
*/

#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

class mat
{
private:
    unsigned int row;
    unsigned int col;
public:
    double *data;
    mat();
    mat(unsigned int size);
    mat(unsigned int R, unsigned int C);
    ~mat();
    void read(string fileName);
    void erease();
    void print();
    void make();
    int getRows();
    int getCols();

    mat operator = (const mat &A);
    mat operator + (const mat &A);
    mat operator * (const mat &A);
};