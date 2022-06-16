#include <iostream>

using namespace std;

int main(void){
	int n;
	
	cout<<"Ingrese un numero entero positivo: "<<endl;
	cin>>n;
	
	for(int i=2;i<n;i++){
		
		int creciente = 2;
		bool esPrimo = true;
		
		while(esPrimo && creciente<i){
		
		    if(i % creciente == 0){
			    esPrimo = false;
		    }
		
		    else{
			    creciente++;	
            }
		
	    }
		
		if(esPrimo){
			cout<<i<<"Es un numero primo"<<endl;
		}    	
    }

}
