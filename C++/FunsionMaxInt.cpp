#include<iostream>

using namespace std;

void mensaje();
int maxInt();

int main(int argc, char **argv){
    mensaje();
    cout << "El valor maximo alcazado por la variable de tipo entero es: "<< maxInt()<<endl;

    return 0;
}


void mensaje(){
    cout<<"\t\t\t UNITEC \n\t \a Programa Valor maximo de la variable tipo entero"<<endl;

}
int maxInt(){
    int A = 1;
    int B = 0;

    while(A > 0){
        B = A;
        A++;
    }
    return B;
}
