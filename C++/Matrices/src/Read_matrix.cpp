#include"../include/Matrices/matlib.hpp"

int main(int arg, char **argv){

    mat M1(2), M2, M3, M4;    
    for(int i0 = 0; i0<M1.getRows();++i0)
        for(int j0 = 0; j0 < M1.getCols();++j0){
            M1.data[i0*M1.getCols()+j0] = i0*M1.getCols()+j0;
        }
    M1.print();
    std::cout<<M2.getRows()<<", "<<M2.getCols()<<endl;
    M2.read("A.txt");
    M2.print();
    std::cout<<M2.getRows()<<", "<<M2.getCols()<<endl;
    M2*2.1;
    M2.save("Producto_constante.txt");
    M3 = M1 + M1;
    M3.print();
    M3.save("Suma.txt");

    cout<<"multiplicación"<<endl;
    M4 = M1*M1;
    M4.print();
    M4.save("producto.txt");

    //M2.print();

    M1.erease();
    M2.erease();
    M3.erease();
    M4.erease();
    return 0;
}