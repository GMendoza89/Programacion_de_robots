#include<iostream>

int main(int argv, char **argc){
	double num;
	double raiz;
	if(argv < 3){
		std::cout<<"Error Faltan argumentos"<<std::endl;
		return -1;

	}else{
		num = atof(argc[1]);
		raiz = atof(argc[2]);
	}

	double error = 1;
	double aprox;
	do{
		aprox = 0.5*(raiz+num/raiz);
			
		error = ((aprox	- raiz)*(aprox - raiz))/(aprox*aprox);
		raiz = aprox;
	}while(error>0.001);
	std::cout<<"La raiz de: "<<num<<"Es aproximadamente igual a: "<< raiz<<std::endl;

	return 0;

}
