#include"punto.hpp"

int main(int argc,char **argv){
   
    float vert[4][2]; // vertices de la figura rectangular

    for(int i = 0; i < 4; i++){
        std::cout << "Ingresa la coordenada x del vertice " << i+1<<": ";
        std::cin >> vert[i][0];
        std::cout << "Ingresa la coordenada y del vertice " << i+1<<": ";
        std::cin >> vert[i][1];
    }

    line2D arist0(vert[0][0],vert[0][1],vert[1][0],vert[1][1]);
    line2D arist1(vert[1][0],vert[1][1],vert[2][0],vert[2][1]);
    line2D arist2(vert[2][0],vert[2][1],vert[3][0],vert[3][1]);
    line2D arist3(vert[3][0],vert[3][1],vert[0][0],vert[0][1]);

    float Perimeter = arist0.getMagnitude() + arist1.getMagnitude() + arist2.getMagnitude() + arist3.getMagnitude();

    std::cout << "El perímetro de la figura con cordenadas:  ";
    for(int i = 0; i < 4; i++){
        std::cout << " ( " << vert[i][0] << ", " << vert[i][1] << ") ";
    }
    std::cout << "es: "<< Perimeter;

    return 0;
}