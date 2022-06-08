/*
Vamos a crear una pila como elemento basico para poder
demostrar que las primeras entradas son las ultimas salidas
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

//Definir la pila

struct Nodo{
	int valor;
	Nodo *siguiente;
};

//Metodos
void insertarPila(Nodo *&, int);
void mostrarPila(Nodo *&);
void eliminarPila(Nodo *&, int);

int main(){
	/*El primero en entrar es el ultimo salir, el ultimo
	que entra es el primero que sale
	*/
	
	int cantidad, i=0, v, op=1;
	//Primera definicion de la Pila
	Nodo *pila = NULL;
	
	while(op!=4){
		cout<<"Selecciona la opcion deseada: ";
		cout<<"1.- Insertar valor: \n";
		cout<<"2.- Mostrar valores: \n";
		cout<<"3.- Eliminar valores: \n";
		cout<<"4.- Salir: \n";
		
		cin>>op;
		
		switch(op){
			case 1:
			    cout<<"Ingresa la cantidad de datos a introducir en la pila: \n";
			    cin>>cantidad;
		    while(i<cantidad){
			cout<<"Ingresa el valor: \n";
			cin>>v;
			insertarPila(pila, v);
			i++;
		    }
		    break;
		
		    case 2:
			mostrarPila(pila);
			break;
		    case 3:
			//Saber si esta vacia
			if(pila==NULL){
				cout<<"No se puede eliminar, pila vacia. \n";
				
			}else{
				cout<<"Eliminar el dato \n";
				while(pila!=NULL){
					eliminarPila(pila, v);
					if(pila!=NULL){
						cout<<"|"<<endl;
						
				    }else{
				    	cout<<" * "<<endl;
					}
			    }
				}
				break;
			default:
				cout<<"La opcion deseada no existe, ni modos\n";
		}
	}		
    return 0;
}


void insertarPila(Nodo *&pila, int v){
	//Creamos el Nodo
	Nodo *insPila = new Nodo();
	insPila -> valor = v;
	insPila -> siguiente = pila;
	pila = insPila;
}

void mostrarPila(Nodo *&pila){
	//Necesitamos un elemente que almacene valores
	Nodo * aux;
	
	if(pila==NULL){
		cout<<"La pila esta vacia, no hay nada que mostrar \n";
	}else{
		aux = pila;
		while(aux!=NULL){
			cout<<"Valor: "<<aux->valor<<endl;
			aux = aux->siguiente;
		}
	}
}

void eliminarPila(Nodo *&pila, int &v){
	Nodo *aux = pila;
	v = aux -> valor;
	pila = aux -> siguiente;
	delete aux;
}

