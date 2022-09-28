#include<iostream>

using namespace std;

int main(int argc, char ** argv){

   int edad = 0;
   int mayoriaEdad;
   mayoriaEdad = 18;
   while(edad < mayoriaEdad){
    edad++;

    if(edad == 1){
        cout << "felicidades cumpliste  "<< edad << " Año"<<endl;
           
    }else{
        cout << "felicidades cumpliste  "<< edad << " Años"<<endl;
        
   }
   }

   cout<< "Felicidades eres mayor de edad"<< endl;
   do{
     edad++;

    if(edad == 1){
        cout << "felicidades cumpliste  "<< edad << " Año"<<endl;
           
    }else{
        cout << "felicidades cumpliste  "<< edad << " Años"<<endl;
        
   }
   }while (edad < 18);
   
   
    return 0;
}

