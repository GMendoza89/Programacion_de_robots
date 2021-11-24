#include"../include/Matrices/matlib.hpp"

/*
* Libreria de matrices
* Autor: Ing. Gustavo David Mendoza Pinto
* 
*
*/

mat::mat(){
    row = 0;
    col = 0;
    data = NULL;
}
mat::mat(unsigned int size){
    row = size;
    col = size;
    data = new double[row*col];

}
mat::mat(unsigned int R, unsigned int C){
    row = R;
    col = C;
    data = new double[row*col];
    
}

mat::~mat(){
    
}
void mat::erease(){
    if(data != NULL){
        delete data;
    }
    data = NULL;
}
void mat::read(string fileName){
    ifstream file;
    file.open(fileName.c_str());
    if(file.is_open()){
        cout<<"Archivo cargado correctamente"<<endl;
    }else{
        cout<<"ERROR - Archivo cargado incorrectamente"<<endl;
        return;
    }
    file>>row;
    file>>col;
    if(data != NULL){
        delete data;
    }
    data = new double[row*col];
    for(int i0 = 0; i0<row;++i0){
        for(int j0 = 0; j0 <col;++j0){
            file>>data[i0*col+j0];
        }
    }
    file.close();
}
void mat::save(string fileName){
    ofstream file;
    file.open(fileName.c_str());
    if(!file.is_open()){
        cout<<"Error - El archivo no se creo correctamente"<<endl;
        return;
    }
    file<<row<<" "<<col<<endl;
    for(int i0 =0; i0<row; i0++){
        for(int j0 = 0; j0<col;++j0){
            file<<data[i0*col+j0]<<" ";
        }
        file<<endl;
    }
    file.close();
}
void mat::print(){
    for(int i0 = 0; i0<row;++i0){
        cout<<" | ";
        for(int j0 = 0; j0 <col;++j0){
            cout<<data[i0*col+j0]<<" ";
        }
        cout<<" | "<<endl;
    }
}
int mat::getRows(){return row;}
int mat::getCols(){return col;}
mat mat::operator = (const mat &A){
    row = A.row;
    col = A.col;
    data = new double[row*col];
    for(int i0 = 0; i0<row; ++i0){
        for(int j0 = 0; j0<col; ++j0){
            data[i0*col+j0] = A.data[i0*col+j0]; 
        }
    }
    return (*this);
}
mat mat::operator + (const mat &A){
    if(row != A.row || col != A.col){
        cout<<"Error matrices de diferentes dimenciones"<<endl;
        return mat();
    }
        

    mat C(row,col);
    
    for(int i0 = 0; i0 < row; ++i0){
        for(int j0 = 0; j0 <col; ++j0){
            C.data[i0*col+j0] = data[i0*col+j0] + A.data[i0*col+j0];
        }
    }
    return C;
}
mat mat::operator - (const mat &A){
    if(row != A.row || col != A.col){
        cout<<"Error matrices de diferentes dimenciones"<<endl;
        return mat();
    }
        

    mat C(row,col);
    
    for(int i0 = 0; i0 < row; ++i0){
        for(int j0 = 0; j0 <col; ++j0){
            C.data[i0*col+j0] = data[i0*col+j0] - A.data[i0*col+j0];
        }
    }
    return C;
}
mat mat::operator * (const mat &A){
    if(col != A.row)
        return mat();
    mat C(row,A.col);
    for(int i0 = 0; i0<row;++i0){
        for(int j0 = 0; j0 <A.col;++j0){
            C.data[i0*col+j0] = 0;
            for(int k0 = 0; k0<col;++k0){
                C.data[i0*col+j0] += data[i0*col+k0] * A.data[k0*A.col+j0];
                //[i0][k] [k][j0]
            }
        }
    }
    return C;
}

mat mat::operator * (const double &K){
    mat C(row,col);
    for(int i0 = 0; i0<row;++i0){
        for(int j0 = 0; j0 <col;++j0){
            C.data[i0*col+j0] = data[i0*col+j0]*K; // [i*ancho + j] = [i][j]
        }
    }
    return C;

}

