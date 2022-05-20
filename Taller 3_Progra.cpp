// Programa realizado por: Carlos Duran

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
class Azar{
	private:
		int lista[50];
	public:
		Azar();
		void desv();
		void mediana();
		void mayor();
		void menor();
		void prom();
		void acum();
		void mostrar();
};
Azar::Azar(){
	srand(time(NULL));
	for(int i=0;i<50;i++){
		lista[i]=rand()%500+1;
	}
}
void Azar::desv(){
	float suma=0,desviacion=0;
	for(int i=0;i<50;i++){
		suma=suma+lista[i];
	}
	float prom=suma/50;
	for(int i=0;i<50;i++){
		desviacion=desviacion+pow(lista[i]-prom,2);
	}
	desviacion=sqrt(desviacion/50);
	cout<<"La desviacion estandar es: "<<desviacion<<endl;
}
void Azar::mediana(){
	int mediana;
	for(int i=0;i<50;i++){
		for(int j=0;j<50;j++){
			if(lista[i]<lista[j]){
				int aux=lista[i];
				lista[i]=lista[j];
				lista[j]=aux;
			}
		}
	}
	if(50%2==0){
		mediana=(lista[24]+lista[25])/2;
	}
	else{
		mediana=lista[24];
	}
	cout<<"La mediana es: "<<mediana<<endl;
}
void Azar::mayor(){
	int mayor=lista[0];
	for(int i=0;i<50;i++){
		if(lista[i]>mayor){
			mayor=lista[i];
		}
	}
	cout<<"El mayor es: "<<mayor<<endl;
}
void Azar::menor(){
	int menor=lista[0];
	for(int i=0;i<50;i++){
		if(lista[i]<menor){
			menor=lista[i];
		}
	}
	cout<<"El menor es: "<<menor<<endl;
}
void Azar::prom(){
	float suma=0,prom;
	for(int i=0;i<50;i++){
		suma=suma+lista[i];
	}
	prom=suma/50;
	cout<<"El promedio es: "<<prom<<endl;
}
void Azar::acum(){
	int acum=0;
	for(int i=0;i<50;i++){
		acum=acum+lista[i];
	}
	cout<<"El acumulado es: "<<acum<<endl;
}
void Azar::mostrar(){
	for(int i=0;i<50;i++){
		cout<<lista[i]<<" ";
	}
	cout<<endl;
}
int main(){
	Azar obj;
	char resp;
	do{
		int op;
		cout<<"Menu"<<endl
			<<"1. Mostrar"<<endl
			<<"2. Desviacion estandar"<<endl
			<<"3. Mediana"<<endl
			<<"4. Mayor"<<endl
			<<"5. Menor"<<endl
			<<"6. Promedio"<<endl
			<<"7. Acumulado"<<endl
			<<"8. Salir"<<endl;
		cin>>op;
		switch(op){
			case 1:
				obj.mostrar();
				break;
			case 2:
				obj.desv();
				break;
			case 3:
				obj.mediana();
				break;
			case 4:
				obj.mayor();
				break;
			case 5:
				obj.menor();
				break;
			case 6:
				obj.prom();
				break;
			case 7:
				obj.acum();
				break;
			case 8:
				cout<<"Gracias por usar el programa"<<endl;
				break;
			default:
				cout<<"Opcion no valida"<<endl;
				break;
		}
		cout<<"Desea continuar? s/n"<<endl;
		cin>>resp;
	}while(resp=='s' || resp=='S');
	return 0;
}
