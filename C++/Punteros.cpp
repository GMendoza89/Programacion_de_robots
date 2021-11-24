#include<iostream>
#include<fstream>

#define PI 3.1416

using namespace std;


void printMensaje();
int sumaEnteros(int A, int B);

int main(int argc, char **argv){


    int *vector;
    double **Mat;


    int numeroElementos;
    unsigned int R, C;
    cout<<"Ingrese el número de elementos en el vector"<<endl;
    cin>>numeroElementos;

    if(numeroElementos<2){
        cout<<"Error vector muy pequeño"<<endl;
        return -1;
    }

    vector = new int(numeroElementos);
    vector[0] = 0;
    vector[1] = 1;
    for(int i0 = 2; i0<numeroElementos;++i0){
        vector[i0] = sumaEnteros(vector[i0-1],vector[i0-2]);
    }

    for(int i0 = 0; i0<numeroElementos;++i0){
        cout << vector[i0]<<", "; 
    }
    cout<<endl;

    cout<<"Ingrese número de Renglones de la matriz"<<endl;
    cin>>R;
    cout<<"Ingrese número de columnas de la matriz"<<endl;
    cin>>C;

    // Asignacion de memoria de la matriz
    Mat = new double*[R];

    for(int i0 = 0; i0<R;++i0){
        Mat[i0] = new double[C];
    }


    //Liberar memoria de la matriz
    for(int i0 = 0; i0<R;++i0){
        delete Mat[i0]; 
    }
    delete Mat;
    delete vector;
    return 0;
}


int sumaEnteros(int A, int B){
    return A+B;
}

void printMensaje(){
    cout<<"Hola a todos"<<endl;
    return;
}