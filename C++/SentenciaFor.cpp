#include<iostream>

using namespace std;

int main(int argc, char ** argv){

   for(int edad = 0 ; edad<18;edad+=2){
    if(edad == 1){
        cout << "felicidades cumpliste  "<< edad << " Año"<<endl;
           
    }else{
        cout << "felicidades cumpliste  "<< edad << " Años"<<endl;
        
   }
   }
   
   
    return 0;
}