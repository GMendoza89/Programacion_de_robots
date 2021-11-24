#include<iostream>

#define PI 3.1416

using namespace std;


void printMensaje();
int sumaEnteros(int A, int B);



int main(int argc, char **argv){

    
    
    int mes[12]; // el primer valor no es 1, es 0; [0 1 2 3 4 5 6 7 8 9 10 11]
    mes[0] = 0;
    mes[1] = 1;

    for(int i0 = 2;i0<12;++i0){
        mes[i0] = sumaEnteros(mes[i0-1],mes[i0-2]);
    } 
    for(int i0 = 0;i0<12;++i0){
        cout<<mes[i0]<<", ";
    }
    cout<< "Ingrese los valores de una matriz de 3 x 3 de uno en uno"<<endl;
    double MatA[3][3];
    for(int i0 = 0; i0<3; ++i0){
        for(int j0 = 0; j0<3; ++j0){
            cout<<i0<<", "<<j0<<": "<<endl;
            cin>> MatA[i0][j0];

        }
    }

    cout<< "La matriz ingresada es"<<endl;
    for(int i0 = 0; i0<3; ++i0){
        for(int j0 = 0; j0<3; ++j0){
            cout<<MatA[i0][j0]<<", ";
        }
        cout << endl;
    }
    return 0;
}


int sumaEnteros(int A, int B){
    return A+B;
}

void printMensaje(){
    cout<<"Hola a todos"<<endl;
    return;
}