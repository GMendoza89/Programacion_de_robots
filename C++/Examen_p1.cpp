#include<iostream>

using namespace std;
int main(int argv, char **argc){

    if(argv<2){
        cout<<"Falta un numero"<<endl;
        return -1;
    }
    int numero = atoi(argc[1]);
    if(numero%2){
        cout<<"El numero es impar"<<endl;
    }else{
        cout<<"El numero es par"<<endl;
    }

    return 0;
}