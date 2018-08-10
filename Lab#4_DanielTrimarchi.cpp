#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <iomanip>
using std::setw;


using namespace std;

void cofactores(){
	int size;

	cout<<"Ingrese el Tamaño de la Matriz NxN[1-6]: "<<endl;
	cin >> size;

	cin >>size;

	if(cin.fail){
	cin.clear;
	cin.ignore;
	cout<<"No es un Numero!!!!!!!!"<<endl;
	}
 
	// ejemplo:
	std::string cad;
	std::cin >> cad;
 
	int numero;
	if(StrToInt(cad, numero))
 	 std::cout << "El número introducido es" << numero << std::endl;
	else
 	 std::cout << "Error!!!" << std::endl;

}
void reversi(){




}
int** createMatrix(int n){
	int** retVal = new int*[n];

	for(int i = 0; i < n; i++){
		retVal[i] = new int[n];
	}
	return retVal;
}

//Liberar memoria
void freeMatrix(int n, int** matrix){
	for(int i = 0; i < n;i++){
		delete[] matrix[i];
	}
	delete[] matrix;

}	

//imprimir una matriz
void printMatrix(int size,int** matrix){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			cout <<" "<<matrix[i][j];
		}
			cout << endl;
	}

}


int main(){
	int resp=0;
	do{
		cout <<endl;
		cout <<"		MENU PRINCIPAL"<<endl
		     <<"1.Matriz de Cofactores "<<endl
		     <<"2. "<<endl
		     <<"3. Salir"<<endl
		     <<"Escoja su respuesta: "<<endl;
		cin>> resp;
		switch (resp){
			case 1:
				cofactores();
				break;
			case 2:
				reversi();
				break;
		}
		if(resp<1||resp>3){
		cout <<"El Numero Ingresado es Invalido. Intente de Nuevo"<<endl;
		}
	}while(resp!=4);
	return 0;
}
