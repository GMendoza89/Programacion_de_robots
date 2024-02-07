#include"punto.hpp"

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


// ---------------------------- Clase Line ----------------------------------

line2D::line2D(/* args */)
{
}

line2D::~line2D()
{
}

line2D::line2D(float x1,float y1, float x2, float y2){
    xi = x1;
    yi = y1;
    xf = x2;
    yf = y2;
}

void line2D::setInitPoint(float x, float y){
    xi = x;
    yi = y;
}
void line2D::setEndPoint(float x, float y){
    xf = x;
    yf = y;
}
float line2D::getInitX(){
    return xi;
}
float line2D::getInitY(){
    return yi;
}
float line2D::getEndX(){
    return xf;
}
float line2D::getEndY(){
    return yf;
}

float line2D::getMagnitude(){
    return sqrt((xf - xi)*(xf - xi) + (yf - yi)*(yf - yi));
}


