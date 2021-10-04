#include<iostream>

#define PI 3.1416

using namespace std;


void printMensaje();
int sumaEnteros(int A, int B);



int main(int argc, char **argv){

    
    
    int mes;
    //char menu;

    
    bool estado = true;
    
    while (estado)
    {
        cout<<"Ingresa el número de un mes"<<endl;
        cin>>mes;/* code */

        switch (mes)
    {
    case 1:
        cout<<"Estas en el glorioso mes de enero "<<endl;
        printMensaje();
        break;
    
    case 2:
        cout<<"Estas en el  mes de los enamorados"<<endl;
        break;
    
    default:
        cout<<" Error mes no valido "<<endl;
        estado = false;
        break;

    }
        
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