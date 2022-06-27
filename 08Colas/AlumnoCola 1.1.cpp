#include <iostream>

using namespace std;

struct ICO{
	char clave[20];
	char nombre[30];
	float calificacion;			
};

struct nodo{
	ICO alumnos;
	nodo* siguiente;
} *primero, *ultimo;


void insertarNodo();
void buscarNodo();
void modificarNodo();
void eliminarNodo();
void desplegarCola();

int main(){	
	int opcion_menu=0;
	do
	{
	cout<<"\nMenu de Alumnos Matriculados\n";
	cout<<"1.- Agregar datos del alumno\n";
	cout<<"2.- Buscar datos del alumno\n";
	cout<<"3.- Modificar datos del alumno\n";
	cout<<"4.- Eliminar datos del alumno\n";
	cout<<"5.- Mostrar datos del alumno\n";
	cout<<"6.- Salir \n";
		cout << endl << endl << " Escoja una Opcion: ";
		cin >> opcion_menu;
		switch(opcion_menu){
			case 1:
				cout << endl << endl << "\n CLAVE \t"<<" NOMBRE \t"<<" CALIFICACION \n" << endl << endl;
				insertarNodo();
				break;
			case 2:
				cout << endl << endl << " BUSCAR DATOS DEL ALUMNO " << endl << endl;
				buscarNodo();
				break;
			case 3:
				cout << endl << endl << " MODIFICAR DATOS DEL ALUMNO " << endl << endl;
				modificarNodo();
				break;
			case 4:
				cout << endl << endl << " ELIMINAR DATOS DEL ALUMNO " << endl << endl;
				eliminarNodo();
				break;
			case 5: 
				cout << endl << endl << " MOSTRAR DATOS DEL ALUMNO " << endl << endl;
				desplegarCola();
				break;
			case 6:
				cout << endl << endl << " Programa finalizado..." << endl << endl;
				break;
			default:
				cout << endl << endl << " Opcion No Valida " << endl << endl;
			}
	} while (opcion_menu != 6);
	return 0;
}             

void insertarNodo(ICO &alumnos){
	nodo* nuevo = new nodo();
	cout << " Ingrese la clave deL Alumno: ";
	cin.getline(alumnos.clave, 20, '\n');
	cout << " Ingrese el nombre deL Alumno: ";
	cin.getline(alumnos.nombre, 30, '\n');
	cout << " Ingrese la calificacion deL Alumno: ";
	cin>>alumnos.calificacion;

	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = primero;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
	}
	cout << endl << " Alumno Ingresado " << endl << endl;
}

void buscarNodo(ICO &alumnos){
	nodo* actual = new nodo();
	actual = primero;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << " Ingrese el dato del Alumno que desea a Buscar: ";
	cin >> nodoBuscado;
	if(primero != NULL){
		while(actual!=NULL && encontrado != true){
			
			if(actual->alumnos.clave, 20, '\n' == nodoBuscado){
				cout << "\n Alumno con el dato ( " << nodoBuscado << " ) Encontrado";
				encontrado = true;
			}
			
			actual = actual->siguiente;
		}
		if(!encontrado){
			cout << "\n Alumno No Encontrado";
		}
	}else{
		cout << endl << " La cola se encuentra Vacia " << endl << endl;
	}	
}

void modificarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << " Ingrese el dato del Alumno a Buscar para Modificar: ";
	cin >> nodoBuscado;
	if(primero != NULL){
		while(actual!=NULL && encontrado != true){
			
			if(actual->alumnos.clave, 20, '\n' == nodoBuscado){
				cout << "\n Alumno con el dato ( " << nodoBuscado << " ) Encontrado";
				cout << "\n Ingrese los nuevos datos para este Alumno: ";
				cin >> actual -> alumnos.clave, 20, '\n';
				cout << "\n Alumno Modificado\n\n";
				encontrado = true;
			}
			
			actual = actual->siguiente;
		}
		if(!encontrado){
			cout << "\n Alumno No Encontrado\n\n";
		}
	}else{
		cout << endl << " La cola se encuentra Vacia " << endl << endl;
	}		
}

void eliminarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	nodo* anterior = new nodo();
	anterior = NULL;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << " Ingrese el dato del Alumno a Buscar para Eliminar: ";
	cin >> nodoBuscado;
	if(primero != NULL){
		
		while(actual!=NULL && encontrado != true){
			
			if(actual->alumnos.clave, 20, '\n' == nodoBuscado){
				cout << "\n Alumno con el dato ( " << nodoBuscado << " ) Encontrado";
				
				if(actual == primero){
					primero = primero -> siguiente;
				}else if(actual == ultimo){
					anterior->siguiente = NULL;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
				}
				
				cout << "\n Alumno Eliminado\n\n";
				
				encontrado = true;
			}
			anterior = actual;
			actual = actual->siguiente;
		}
		if(!encontrado){
			cout << "\n Alumno No Encontrado\n\n";
		}
	}else{
		cout << endl << " La cola se encuentra Vacia " << endl << endl;
	}	
}

void desplegarCola(){
	nodo* actual = new nodo();
	actual = primero;
	if(primero!=NULL){
		while(actual!=NULL){
			cout << endl << " " << actual->alumnos.clave, 20, '\n';
			actual = actual->siguiente;
		}
	}else{
		cout << endl << " La cola se encuentra Vacia " << endl << endl;
	}
}
