#include<iostream>
 using namespace std;

int main(int argc, char **argv){
    int numero;
    cout<<"Escriba un numero"<<endl;
    cin>>numero;
    long int factorial;
    factorial = numero;
    for(int i0 = numero-1; i0 > 1;i0--){
        factorial *= i0;
    }
    cout<<factorial<<endl;
    return 0;
}