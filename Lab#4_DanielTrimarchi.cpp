#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <iomanip>
using std::setw;


using namespace std;
void cofactores();
int** createMatrix(int);
void reversi();
void freeMatrix(int,int**);
void printMatrix(int,int**);
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
	}while(resp!=3);
	return 0;
}

void cofactores(){
	int size;
	bool paso=false;
	do{
	cout<<"Ingrese el Tamaño de la Matriz NxN: "<<endl;
	cin >> size;

	if(cin.fail()) {
  	 cin.clear(); 
  	  /*Comunicas que ya has verificado los errores. A partir de esta linea es como si no
  	  hubieran ocurrido, aunque en un futuro es posible que ocurran mas*/
 
	    cin.ignore();
	 cout<<"No es un numero..."<<endl;
  	  /*Si el parametro vale exactamente std::numeric_limits<std::streamsize>::max(),
   	 entonces se ignora todo hasta el caracter fin de línea*/
	}else{
		if(size<0){
		paso=false;

		}else{	
		paso=true;
		}
	}
	}while(paso==false );
	int** matrix= createMatrix(size);		
	
	int cord,cord2;
	do{
	cout<<"Ingrese la posicion de i [0-(size-1) :";
	cin>> cord;
	cout<<"Ingrese la posicion de j [0-(size-1) :";
		cin>> cord2;
	}while(cord<0||cord2<0||cord2>=size||cord>=size);
	for(int i=0;i<size;i++){
		int cont=0;
		if(i%2==0){
			cont=1;
		}else{
			cont=2;	
		}	
		for(int j=0;j<size;j++)	{
			int num = rand() % 6 + 1;		
			if(cont==1){
			matrix[i][j]=num;
			cont=2;	
			}else{	
			matrix[i][j]=num*-1;
			cont=1;
			}
			if(i==cord||j==cord2){
			matrix[i][j]=0;
			}	
		}	
	
	
	}

		//Lee por segunda vez la matrix


	printMatrix(size,matrix);
	freeMatrix(size,matrix);	
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
void freeMatrix(int  n, int** matrix){
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


