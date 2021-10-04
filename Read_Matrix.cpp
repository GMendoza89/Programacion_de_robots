#include<iostream>
#include<fstream>
using namespace std;

struct Matrix
{
    int rows, cols;
    double **data;
};

void copyMatrix(Matrix *A, Matrix *B);
void saveMatrix(Matrix *A);

int main(int argc, char **argv){

    
    string Name;
    Matrix M, M2;
    cout<<"Ingrese el nombre del archivo con la matriz"<<endl;
    cin>>Name;

    ifstream file;
    file.open(Name.c_str());

    if(file.is_open()){
        cout<<"Archivo cargado correctamente"<<endl;
    }else{
        cout<<"ERROR - Archivo cargado incorrectamente"<<endl;
        return 1;
    }
    file>>M.rows;
    file>>M.cols;

    M.data = new double*[M.rows];
    for(int i0 = 0; i0<M.rows;++i0){
        M.data[i0] = new double[M.cols];
    }

    for(int i0 = 0; i0<M.rows;++i0){
        for(int j0 = 0; j0 <M.cols;++j0){
            file>>M.data[i0][j0];
        }
    }
    file.close();

    cout<<"Los datos de la matriz son:"<<endl;
    for(int i0 = 0; i0<M.rows;++i0){
        cout<<"| ";
        for(int j0 = 0; j0 <M.cols;++j0){
            cout<<M.data[i0][j0]<<" ";
        }
        cout<<" |"<<endl;
    }

    copyMatrix(&M, &M2);
    

    cout<<"Los datos de la copia de la matriz son:"<<endl;
    for(int i0 = 0; i0<M2.rows;++i0){
        cout<<"| ";
        for(int j0 = 0; j0 <M2.cols;++j0){
            cout<<M2.data[i0][j0]<<" ";
        }
        cout<<" |"<<endl;
    }

    saveMatrix(&M2);


    for(int i0 = 0; i0<M.rows;++i0){
        delete M.data[i0];
    }
    delete M.data;

    for(int i0 = 0; i0<M2.rows;++i0){
        delete M2.data[i0];
    }
    delete M2.data;    

    return 0;
}

void copyMatrix(Matrix *A, Matrix *B){
    B->rows = A->rows;
    B->cols = A->cols;
    B->data = new double*[B->rows];
    for(int i0 = 0; i0<B->rows;++i0){
        B->data[i0] = new double[B->rows];
    }

    for(int i0 = 0; i0<A->rows;++i0){
        for(int j0 = 0; j0 <A->cols;++j0){
            B->data[i0][j0] = A->data[i0][j0]+1;
        }
    }   
    
}

void saveMatrix(Matrix *A){
    ofstream Archivo;
    Archivo.open("Matriz.txt");

    Archivo<<A->rows<<" "<<A->cols<<endl;
    
    for(int i0 = 0; i0<A->rows;++i0){
        for(int j0 = 0; j0 <A->cols;++j0){
            Archivo<<A->data[i0][j0]<<" ";
        }
        Archivo<<endl;
    }
    Archivo.close();
}