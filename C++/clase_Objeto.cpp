#include<iostream>

class punto2D
{
private:
    /* data */
    float x;
    float y;
public:
    punto2D(/* args */);
    punto2D(float X, float Y);
    ~punto2D();
    void establecerCordenadas(float X, float Y);
    float obtenerX();
    float obtenerY();
   

    float distancia(punto2D B);
};

punto2D::punto2D(/* args */)
{
    x = 0.0;
    y = 0.0;
}
punto2D::punto2D(float X, float Y){
    x = X;
    y = Y;
}

punto2D::~punto2D()
{
}

float punto2D::distancia(punto2D B){
    return sqrt( (B.x - x)*(B.x - x) + (B.y - y)*(B.y - y));
}

void punto2D::establecerCordenadas(float X, float Y){
    x = X;
    y = Y;
}
float punto2D::obtenerX(){
    return x;
}

float punto2D::obtenerY(){
    return y;
}


int main(int argc,char **argv){

    punto2D A, B, C;
    punto2D D(-2.5,-2.5);

    // A.x = 2.1;
    // A.y = 3.85;
    A.establecerCordenadas(2.1,3.85);
    // B.x = -2.85;
    // B.y = 9.16;
    B.establecerCordenadas(-2.85,9.16);


    std::cout<<"Las coordenadas del punto A son ("<< A.obtenerX() << ", "<< A.obtenerY() << ")\n";
    std::cout<<"Las coordenadas del punto B son ("<< B.obtenerX() << ", "<< B.obtenerY() << ")\n";
    std::cout<<"Las coordenadas del punto C son ("<< C.obtenerX() << ", "<< C.obtenerY() << ")\n";
    std::cout<<"Las coordenadas del punto D son ("<< D.obtenerX() << ", "<< D.obtenerY() << ")\n";

    std::cout<<"La distancia entre los puntos A y B es:  "<< A.distancia(B) << ")\n";
    std::cout<<"La distancia entre los puntos C y D es:  "<< C.distancia(D) << ")\n";

    
    return 0;
}
