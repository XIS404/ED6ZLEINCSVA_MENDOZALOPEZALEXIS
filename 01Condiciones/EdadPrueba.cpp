
#include<iostream>
//determinar las entradas y salidas del codigo

using namespace std; 
 /*
 IOStream nos sirve para dictaminar los in del sistema por parte del teclado os del sistema es la salida estandar que es pantalla
 */
 
 main(){
 	//declaracion de variables 
 	//programa que nos diga si la persona es mayor de edad
 	int edad;
 	//salida en la pantalla
 	cout<<"Ingresa tu edad, para determinar si eres mayor de edad \n";
 	
 	//entrada de datos
 	cin>>edad;
 	
 	while (edad <=0){
 	cout<<"error \n";
 	cin>>edad;
	 }

	 	
 	if( edad >=18){
 		cout<<"Es mayor de edad";	
	 }else{
	 	cout<<"Es menor de edad";
	 }
 }
