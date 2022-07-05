/*
Ejemplo de cola con prioridades
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

//vamos con la estructura nodo

struct nodo{
	string dato;
	int prioridad;
	struct nodo * siguiente;
};


//estructura de la cola
struct cola{
	nodo *delante;
	nodo *atras;
};

//funcion para crear un nodo nuevo

struct nodo *crearNodo(string x, int pri){
	//vamos a crear ese nuevo nodo
	struct nodo *nuevoNodo = new (struct nodo);
	nuevoNodo->dato=x;
	nuevoNodo->prioridad=pri;
	return nuevoNodo;
}


void encolar(struct cola &q, string valor, int priori){
	//necesito mi auxiliar
	struct nodo *aux = crearNodo(valor, priori);
	aux->siguiente=NULL;
	
	if(q.delante == NULL){
		//es el primero en encolar
		q.delante=aux;
	}else{
		(q.atras)->siguiente = aux;
	}
	//siempre el aux debe apuntar al final
	q.atras = aux;
}


void mostrarCola(struct cola q){
	//auxliar
	struct nodo *aux;
	
	aux = q.delante;
	
	cout<<"\n Turno asignado: \n";
	
	while(aux!=NULL){
		//hay datos
		cout<<" "<<aux->dato<<" Su turno es la prioridad: "<<aux->prioridad<<endl;
		aux = aux->siguiente;
	} 
}


void ordenarPrioridad(struct cola &q){
	//criterio de 0 como prioridad
	//el numero mayor es la mas alta
	
	struct nodo *aux1, *aux2;
	int p_aux;
	string c_aux;
	
	aux1 = q.delante;
	
	while(aux1->siguiente != NULL){
		aux2 = aux1->siguiente;
		while(aux2!=NULL){
			if(aux1->prioridad > aux2->prioridad){
				p_aux = aux1->prioridad;
				c_aux = aux1->dato;
				
				aux1->prioridad = aux2->prioridad;
				aux1->dato = aux2->dato;
				
				aux2->prioridad = p_aux;
				aux2->dato = c_aux;
			}
			aux2=aux2->siguiente;
		}
		aux1 = aux1->siguiente;
	}
}

void insertar(struct cola &q, string c, int pri){
	
	//encolar
	encolar(q, c, pri);
	
	//ordeno
	ordenarPrioridad(q);
	//nuevo comentario
}

void menu(){
	cout<<"\n Bienvenido/a\n";
	cout<<"\n Seleccione la opcion que desea realizar\n";
	cout<<"1.- Ingresar nombre y tipo de cuenta del Tarjeta Habiente\n";
	cout<<"2.- Realizar un deposito \n";
	cout<<"3.- Mostrar Tarjeta Habientes y asignar turno \n";
	cout<<"3.- Mostrar Tarjeta Habientes y asignar turno \n";
	cout<<"5.- Salir \n";
	
	
}

int main(){
	struct cola q;
	
	q.delante = NULL;
	q.atras = NULL;
	
	string c; //caracter del dato
	float d; 
	int priori; //prioridad
	int op; //opcion
	int x; //numero que devuelve para pop
	
	do{
		menu();
		cin>>op;
		switch(op){
			case 1:
				cout<<"Ingrese su nombre, por favor\n";
				cin>>c;
				cout<<"\n Ingrese el tipo de cuenta que posee: \n";
				cout<<"1.- VIP\n";
				cout<<"2.- Empresarial\n";
				cout<<"3.- Normal\n";
				cout<<"4.- Sin cuenta\n";
				cin>>priori;
				
				insertar(q, c, priori);
				
				cout<<"\n El tarjetahabiente "<<c<<" ingresado correctamente \n";
				break;
			case 2:
				cout<<"\n Depositos\n";
				cout<<"\n Ingrese la cantidad que desea depositar: \n";
				cin>>d;
				if(d > 5000){
					cout<<"Ingrese una cantidad menor por favor";
				}else{
					cout<<"\n Se depositaron "<<d<<" de forma exitosa\n";	
				}
				break;
			case 3:
				cout<<"\n Mostrar los Tarjeta Habientes: \n";
				if(q.delante!=NULL){
					mostrarCola(q);
				}else{
					cout<<"\n La cola esta vacia\n";
				}
				break;
			case 4:
				cout<<"Gracias por su visita"; 
			default:
				cout<<"Ingrese una opcion valida\n";
				system("pause");
				exit(0);			
		}
		system("pause");
		system("cls");
	}while(op!=4);
	return 0;
}
