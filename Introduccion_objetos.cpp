#include<iostream>

class Punto{
    private:
    double x,y;

    public:
    Punto();
    ~Punto();
    void setX(double X);
    void setY(double Y);
    double getX();
    double getY();

    double Distancia(Punto P);
};

Punto sumaDePuntos(Punto A, Punto B);
/**
 *   Fucion Principal 
 * 
*/

int main(int argc, char **argv){

    Punto P1,P2,P3;
    P1.setX(3.94);
    P1.setY(4.92);
    P2.setX(0.94);
    P2.setY(3.1416);

    P3 = sumaDePuntos(P1,P2);
    std::cout<<"Las coordenadas del punto 3 son "<<P3.getX() << " , "<< P3.getY()<<std::endl;


    return 0;
}
Punto::Punto(){
    x = 0;
    y = 0;
}
Punto::~Punto(){
    
}
void Punto::setX(double X){
    x = X;
}

void Punto::setY(double Y){
    y = Y;
}
double Punto::getX(){ return x; }
double Punto::getY(){ return y;}

Punto sumaDePuntos(Punto A, Punto B){
    Punto C;
    C.setX(A.getX()+B.getX());
    C.setY(A.getY()+B.getY());
    return C;
}