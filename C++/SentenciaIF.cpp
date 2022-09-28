#include<iostream>

using namespace std;

int main(int argc, char ** argv){

    int variable_a;
    cout << "Ingresa un número: ";
    cin >> variable_a;
    
    if(variable_a%2 == 1){
        cout<<"\nEl número ingrasado es impar\n";
    }else{
        cout<<"\nEl número ingrasado es par\n";

    }

    return 0;
}