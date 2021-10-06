#include"matrix.hpp"

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

    Bici B1("Benoto","Montana",26, 1);
    Motocicleta moto1("Yamaha","pista",29, 1231231, 250);


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

    cout<<"Los datos de la bicicleta son"<<endl;
    cout<<B1.marca<<", "<<B1.tipo<<", "<< B1.rodada << ", "<< B1.serial_n<<endl;
    cout<<"Los datos de la Motocicleta son"<<endl;
    cout<<moto1.marca<<", "<<moto1.tipo<<", "<< moto1.rodada << ", "<< moto1.serial_n<<", "<<moto1.CC<<endl;

    return 0;

}