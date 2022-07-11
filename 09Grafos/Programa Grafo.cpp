/*
Vamos a suponer que vamos a
tener el siguiente grafo

5 3
1 2
2 3
4 5

Con su correspondiente direccion
de la arista
*/

#include<stdio.h>
#include<vector>
#include<cstring>
//Libreria cstring sirve para poder hacer operaciones con cadenas
//Para manipular los caracteres de la Matriz

using namespace std;

//Definir un tamaño para el vector de memoria

#define MAX 10001

vector<int> ady[MAX];

/*
Tenemos que tener una variable que detecte el recorrido
para saber si ya visito el nodo


Otro que se va a encargar de saber el nodo
*/

bool visitado[MAX]; //El Camino o arista
bool visitado_componente[MAX]; //Este es el nodo

//Algoritmo del recorrido mas corto

void dfs(int u){
	//Saber si ya visitaste el camino o arista
	visitado[u] = true;
	//Saber si ya visite el nodo
	visitado_componente[u] = true;
	for(int v = 0; v<ady[u].size(); v++){
	    if(!visitado[ady[u][v]]){
	        dfs(ady[u][v]);
		}
	}
}

int main(){
	//Variables para el grafo
	int V, E, u, v;
	
	//Obtengo los elementos a la memoria
	scanf("%d, %d", &V, &E);
	
	//Creo el Ciclo que se encarga de meter, sacar, entrar y salir del nodo
	
	while(E--){
		scanf("%d, %d", &u, &v);
		ady[u].push_back(v);
		ady[u].push_back(u);
	}


	while(E--){
		printf("Ingresa el nodo y su arista: \n");
		scanf("%d, %d", &u, &v);
		ady[u].push_back(v);
		ady[u].push_back(u);
	}

	printf("Cantidad de nodos conexos: \n");
	int total = 0;

	/*
	hay que saber todos los caminos del nodo, y su peso
	correspondiente, para ello necesitamos obtener
	el camino, el inicio y su tamaño o peso
	*/

	//vamos a ocupar una funcion propia del grafo
	memset(visitado, 0, sizeof(visitado));
	//meter en un ciclo para saber todos los posibles
	//caminos de los nodos
	for(int i = 1; i<= V; ++i){
		if(!visitado[i]){
			memset(visitado_componente, 0, sizeof(visitado_componente));
			dfs(i);
			printf("Componente : %d", total+1);
			//recorrer los valores del componente
			for(int j = 1; j<=V; ++j){
				if(!visitado_componente[j]){
					printf(" %d ", j);
				}
			}
			printf("\n");
			total++;
		}
	}
	printf("%d \n", total);
	return 0;
}

