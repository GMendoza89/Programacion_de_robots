#include<iostream>

using namespace std;
int main(int argv, char **argc){

    // if(argv<2){
    //     cout<<"Falta un numero"<<endl;
    //     return -1;
    // }
    // int numero = atoi(argc[1]);
    double a, b, c, d, e, f;
    if(argv < 7){
        cout<<"Ingrese el valor del coeficiente a: ";
    cin>>a;
    cout<<"\n Ingrese el valor del coeficiente b: ";
    cin>>b;
    cout<<"\n Ingrese el valor del coeficiente c: ";
    cin>>c;
    cout<<"\n Ingrese el valor del coeficiente d: ";
    cin>>d;
    cout<<"\n Ingrese el valor del coeficiente e: ";
    cin>>e;
    cout<<"\n Ingrese el valor del coeficiente f: ";
    cin>>f;
    }else{
        a = atof(argc[1]);
        b = atof(argc[2]);
        c = atof(argc[3]);
        d = atof(argc[4]);
        e = atof(argc[5]);
        f = atof(argc[6]);
    }
    
    

    double denominador = a*e-b*d;
    if(denominador == 0){
        cout<<"Error la ecuacion no tiene solucion"<<endl;
    }else{
        cout<<"El conjunto Solucion es X = "<<(c*e-b*f)/denominador <<" Y = "<<(a*f-c*d)/denominador<<endl; 
    }

    return 0;
}