#include"matrix.hpp"

void copyMatrix(Matrix *A, Matrix *B){
    B->rows = A->rows;
    B->cols = A->cols;
    B->data = new double*[B->rows];
    for(int i0 = 0; i0<B->rows;++i0){
        B->data[i0] = new double[B->rows];
    }

    for(int i0 = 0; i0<A->rows;++i0){
        for(int j0 = 0; j0 <A->cols;++j0){
            B->data[i0][j0] = A->data[i0][j0]+1;
        }
    }   
    
}

void saveMatrix(Matrix *A){
    ofstream Archivo;
    Archivo.open("Matriz.txt");

    Archivo<<A->rows<<" "<<A->cols<<endl;
    
    for(int i0 = 0; i0<A->rows;++i0){
        for(int j0 = 0; j0 <A->cols;++j0){
            Archivo<<A->data[i0][j0]<<" ";
        }
        Archivo<<endl;
    }
    Archivo.close();
}

Bici::Bici(){
    marca = " ";
    tipo = " ";
    rodada = 24;
    serial_n = 0;

}
Bici::Bici(string M, string T, int R,unsigned int SN ){
    marca = M;
    tipo = T;
    rodada = R;
    serial_n = SN;

}
Bici::~Bici(){

}
Motocicleta::Motocicleta(){
    marca = " ";
    tipo = " ";
    rodada = 24;
    serial_n = 0;
    CC = 75;
}
Motocicleta::Motocicleta(string M, string T, int R,unsigned int SN, int cc ){
    marca = M;
    tipo = T;
    rodada = R;
    serial_n = SN;
    CC = cc;
    
}
Motocicleta::~Motocicleta(){
    
}