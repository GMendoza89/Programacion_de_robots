#ifndef PUNTO_HPP
#define PUNTO_HPP

#include<iostream>

class punto2D{
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
class line2D

{
private:
    float xi,yi,xf,yf;

public:
    line2D(/* args */);
    line2D( float x1, float yt1, float x2, float y2);
    ~line2D();
    
    void setInitPoint(float x, float y);
    void setEndPoint(float x, float y);
    float getInitX();
    float getInitY();
    float getEndX();
    float getEndY();

    float getMagnitude();


};


#endif