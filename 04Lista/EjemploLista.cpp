/*

Una lista es una estructura de datos que deriva una secuencia conectada con nodos
y cada uno de los cuales contiene un dato
Hay un nodo al comienzo llamado la cabeza o frente
Hay un nodo al termino llamado cola o atras

La lista solo puede ser recorrida en secuencia de atras o hacia adelante
Una lista va a tener operaciones de su propia estructura

Añadir o insentar elemento, mover a traves de la listra principio a fin
Buscar elementos

Apuntadores
& memoria
* al dato 
-> asignacion

En CC++ vamos a ocupar list ya que es una clase de tipo templete
El tipo templete nos permite crear listas que contengan cualquier tipo de objeto

Las operaciones que se pueden incluir en la lista son:
push meter
pop sacar
begin() comienzo
end() final
size() tamaño
empty() vacio

*/

#include<iostream>

using namespace std;

//definir la estrucutra de la lista
struct nodo{
	//los valores de la lista
	int valor;
	nodo *siguiente;
};

//definir los metodos
void insertarLista(nodo *&, int);

int main(){
	//declarar mi variable de la lista
	//que apunte a null
	nodo *lista = NULL;
	
	//variables
	int op = 1, c, i=0, valores;
	
	cout<<"Trabajando con listas (simples, doblemente enlazadas, circulares y circulares dobles)"<<endl;
	while(op!=3){
		cout<<"Ejemplo de lista simple: "<<endl;
		cout<<"1.- Insertar nuevo valor "<<endl;
		cout<<"2.- Ver lista "<<endl;
		cout<<"3.- Salir "<<endl;
		cin>>op;
		switch(op){
			case 1:
				cout<<"Indica el numero de valores a introducir \n";
				cin>>valores;
				while(i<valores){
					cout<<"Valor["<<i<<"] \n";
					cin>>c;
					//insertar el valor
					insertarLista(lista, c);
					i++;
				}
				break;
		   case 2:
			    cout<<"Mostrar los valores de la lista \n";
			    cout<<"Imprimir valores";
			    break;
			default:
			    cout<<"Gracias por mimir aqui uwu";
	    }
	}
	return 0;
}


void insertarLista(nodo *&lista, int c){
	//crear una nueva lista
	nodo *inslista = new nodo();
	//debo asignar el valor de la lista
	inslista->valor = c;
	
	//necesito un auxiliar para encadenar los valores de la lista
	nodo * aux = lista;
	nodo * aux2;
	//meter los valores de forma ordenada
	while((aux!=NULL) && (aux->valor < c)){
		aux2 = aux;
		aux = aux->siguiente;
	}
	if(inslista==aux){
		lista = inslista;
	}else{
		aux2->siguiente = inslista;
	}
	
	inslista -> siguiente = aux;
	cout<<"Elemento "<<c<<"Insertado"<<endl;
}






