#include<iostream>


int main(int argc,char **argv){
    signed short int a;
    unsigned short int b;
    signed int c;
    unsigned int d;
    signed long int e;
    unsigned long int f;
    float pi = 3.1416;
    double PI = 3.14159;

    a = 32768;
    b = 32768;
    c = 2147483648;
    d = 2147483648;
    e = 2147483648;
    f = 2147483648;
    
    
    std::cout<<"El valor de la variable a es: "<< a << " y su  tamaño de memoria es "<< sizeof(a) << "bytes \n";
    std::cout<<"El valor de la variable b es: "<< b << " y su  tamaño de memoria es "<< sizeof(b) << "bytes \n";
    std::cout<<"El valor de la variable c es: "<< c << " y su  tamaño de memoria es "<< sizeof(c) << "bytes \n";
    std::cout<<"El valor de la variable d es: "<< d << " y su  tamaño de memoria es "<< sizeof(d) << "bytes \n";
    std::cout<<"El valor de la variable e es: "<< e << " y su  tamaño de memoria es "<< sizeof(e) << "bytes \n";
    std::cout<<"El valor de la variable f es: "<< f << " y su  tamaño de memoria es "<< sizeof(f) << "bytes \n";
    std::cout<<"El valor de la variable pi es: "<< pi << " y su  tamaño de memoria es "<< sizeof(pi) << "bytes \n";
    std::cout<<"El valor de la variable PI es: "<< PI << " y su  tamaño de memoria es "<< sizeof(PI) << "bytes \n";
    return 0;
}