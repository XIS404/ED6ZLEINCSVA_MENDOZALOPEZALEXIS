//Uso de arreglos en C++

#include <iostream>

using namespace std;

int main(){
	//Declaracion de arreglos
	int numero[5] = {200, 150, 100, -50, 300};
	int suma;
	
	//Quiero un programa que sume el contenido de un arreglo
	
	//Definicion de valores
	/*numero[0] = 200;
	numero[1] = 150;
	numero[2] = 100;
	numero[3] = -50;
	numero[4] = 300;*/
	
	//suma = numero[0]+numero[1]+numero[2]+numero[3]+numero[4];
	
	suma = 0;
	
	for(int i=0; i<=4; i++){
	suma += numero[i];}
	cout <<"La suma es de: " <<suma;
	
	return 0;
}
