#include<iostream>

using namespace std;
struct matriz
{
    unsigned int rows, cols;
    double **data;
};

// struct Alumno
// {
//     char nombre[110];
//     unsigned int age;
//     char grupo[20];
//     unsigned int NUA;
// };


void makeMatriz(matriz *A, int r, int c);
void deletMatriz(matriz *A);

int main(int argc, char **argv){

    // Alumno A1;
    // A1.nombre = "Pablo Diego José Francisco de Paula Juan Nepomuceno María de los Remedios Crispiniano de la Santísima Trinidad Ruiz Picasso";
    // A1.age = 20;
    // A1.grupo = "Programacion";
    // A1.NUA = 386745;
    // Alumno A2;

    matriz B;

    makeMatriz(&B,3,3);

    for(int i0 = 0; i0<B.rows;++i0){
        for(int j0 = 0; j0<B.cols; ++j0){
            B.data[i0][j0] = i0*3+j0;
            //cout<<i0*3+j0<<endl;
        }
    }

    for(int i0 = 0; i0<B.rows;++i0){
        for(int j0 = 0; j0<B.cols; ++j0){
            cout<<B.data[i0][j0]<<endl;
        }
    } 
    deletMatriz(&B);
    return 0;

}

void makeMatriz(matriz *A, int r, int c){

    A->rows = 3;
    A->cols = 3;

    A->data = new double*[r];
    for(int i0 = 0; i0 < r; ++i0){
        A->data[i0] = new double[c];
    }
    cout<<"Matriz creada"<<endl;
}

void deletMatriz(matriz *A){
     
    for(int i0 = 0; i0 < A->rows; ++i0){
        delete A->data[i0];
    }
    delete A->data;
}