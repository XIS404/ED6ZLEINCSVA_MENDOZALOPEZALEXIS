#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <iostream>

using namespace std;
 
struct dato {
 int i;
 dato *s;
 }*a, *i, *p, *e;
 
int da;
 
int buscar(int d);
void insertar(int dat);
void mostrar(void);
void borrar(void);
void menu(void);
void guardar(void);
void cargar(void);
 
main()
 {
 menu();
 }
 
void menu(void)
{
    int opc,da;
    do{
		cout<<"\n Ejemplo de una lista con apuntadores ";
		cout<<"\n 1.- Buscar datos: ";
		cout<<"\n 2.- Insertar datos: ";
		cout<<"\n 3.- Mostrar datos: ";
		cout<<"\n 4.- Borrar datos: ";
		cout<<"\n 5.- Guardar datos en un archivo: ";
		cout<<"\n 6.- Cargar datos en un archivo: ";
		cout<<"\n 7.- Salir";
		cout<<"\n Seleccione la opcion deseada: ";
        cin>>opc;
        
    switch(opc){
 	        case 1: cout<<"\n Ingrese el dato a buscar: ";
            cin>>da;
            if(buscar(da)){
			    cout<<"\n El dato NO existe";
            }else{
            	cout<<"\n Dato no encontrado, suerte para la proxima";
				getch();
			}
			break;
            case 2: cout<<"\n Ingrese dato: ";
            cin>>da;
            insertar(da);
            break;
            case 3: mostrar();
            break;
            case 4: borrar();
			break;
			case 5: guardar();
			break;
			case 6: cargar();
			break;
			case 7: cout<<"\n Hasta la proximaaaa!";
			getch();
 p=i;
 while(p)
 {
 a=p;
 p=p->s;
 delete(a);
 }
 exit(0);
 default: cout<<"\n Opcion NO Valida";
 getch();
 }
 }while(opc);
 }

void mostrar(void){
    int cont=1;
	if(!i)
	{	
	cout<<"\n No se encuentra lista para mostrar";
	getch();
	return;
	}
    p=i;
	cout<<endl<<endl;
	while(p){
	cout<<cont++<<" - Valor = "<<p->i<<endl;
	p=p->s;
	}
	cout<<"\n Esos son todos los datos hasta el momento";
	getch();
 }
 
int buscar(int d)
    {if (!i){
	cout<<"\n No se encontraron datos en la lista";
	getch();
	return(0);
	}
	p=i;
	a=NULL;
	while(p->s && p->i<d){
	a=p;
	p=p->s;
	}
	return(p->i==d?1:0);
	}
 
void insertar(int dat){
    if(!i){
	i=new(dato);
	i->s=NULL;
	i->i=dat;
	return;
	}
	if(buscar(dat))
	{
	cout<<"\n Dato existente";
	getch();
	return;
	}
	e=new(dato);
	e->i=dat;
	if(p==i && p->s)
	{
	e->s=p;
	i=e;
	return;
	}
	if(p==i && !p->s)
	{
	if(p->i < e->i)
	{
	p->s=e;
	e->s=NULL;
	}else
	{
	e->s=p;
	i=e;
	}
	return;
	}
	if(p->s)
	{
	a->s=e;
	e->s=p;
	return;
	}
	if(e->i > p->i)
	{
	e->s=NULL;
	p->s=e;
	}else
	{
	a->s=e;
	e->s=p;
	}
}
 
 void borrar(void){
    cout<<"\n Ingrese dato que desea eliminar: ";
    cin>>da;
	if(buscar(da))
	{
	if(a)
	a->s=p->s;
	else
	i=p->s;
	delete(p);
	cout<<"\n Dato eliminado";
	}else
	cout<<"\n Dato no encontrado";
	getch();
 }
 
 void guardar(void){
    FILE *arch;
	arch=fopen("DATOS-A.TXT","w");
	if(!i)
	{
	cout<<"\n NO hay lista que pueda guardar";
	getch();
	return;
	}
	p=i;
	while(p)
	{
	fprintf(arch,"%i\n",p->i);
	p=p->s;
	}
	cout<<"\n Archivo Guardado con exito";
	fclose(arch);
	getch();
	}
 
void cargar(void){
    int c,x;
	FILE *arch;
	arch=fopen("DATOS-A.TXT","r");
	if(!arch)
	{
	cout<<"\n NO se ha encontrado el Archivo deseado efe";
	getch();
	return;
	}
	do{
	c=fscanf(arch,"%i\n",&x);
	if(c!=EOF)
	{
	insertar(x);
	}
	}
	while (c!=EOF);
	cout<<"\n Archivo Cargado con exito";
	fclose(arch);
	getch();
	}
