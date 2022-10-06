#include<iostream>

using namespace std;

void mensaje();
int sumaEnteros(int numeroA, int numeroB); // prototipo de funcion

int main(int argc, char **argv){

    int A, B, C;
    mensaje();
    cout<< "En ingresa el valor del numero A: ";
    cin >> A;
    cout<< "En ingresa el valor del numero B: ";
    cin >> B;

    C = sumaEnteros(A,B);

    cout <<"El resultado es: "<< C<<endl;

    return 0;
}


void mensaje(){
    cout<<"\t\t\t UNITEC \n\t \a Programa sumador de numeros enteros"<<endl;

}
int sumaEnteros(int numeroA, int numeroB){
    return numeroA + numeroB;
}
