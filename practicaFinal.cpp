#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>

using namespace std;

void menu();
void encriptar();
void desencriptarTodo();
void desencriptarEspecifico();
void mostrar();

int main(){
	menu();
	return 0;
}

void menu(){
	int opcion;
	
	do{
		cout<<"1. ingresar texto para encriptar"<<endl
			<<"2. desencriptar todo el texto del archivo"<<endl
			<<"3. desencriptar texto específico"<<endl
			<<"4. mostrar texto encriptado"<<endl
			<<"5. salir"<<endl;
			cin>>opcion;
			
			switch(opcion){
				case 1:
					encriptar();	
					break;
				
				case 2:
					desencriptarTodo();
					break;
				
				case 3:
					desencriptarEspecifico();
					break;
					
				case 4:
					mostrar();		
					break;
			}
	}while(opcion!=5);
}

void encriptar(){
	
	int i=0;
	string frase; 
	ofstream archivo, archivoEncriptado;
	char rpt;
	
	archivo.open("archivo.txt",ios::app);
	archivoEncriptado.open("archivoEncriptado.txt",ios::app);
	
	if(archivo.fail()){
		cout<<"Error al abrir el archivo"<<endl;
		exit(1);
	}
	do{
		fflush(stdin);
		cout<<"escriba texto para encriptar"<<endl;
		getline(cin, frase);
		int aux = frase.length();
		char texto[aux];
		for(int i=0;i<frase.length(); i++){
			texto[i] = frase[i];
		}
		archivo<<frase;
		archivo<<"\n";
		
		while(texto[i] !='\0'){
			texto[i] = texto[i]+12-4;
			archivoEncriptado<<texto[i];
			i++;
		}
		i=0;
		archivoEncriptado<<"\n";
		cout<<"desea agregar otra frase? (s/n)"<<endl;
		cin>>rpt;
	
		
	}while((rpt == 'S')||(rpt == 's'));
	archivo.close();
	cout<<"\n============================================================="<<endl<<endl;
}

void desencriptarTodo(){
	ifstream archivo;
	string frase;
	int i=0;

	archivo.open("archivoEncriptado.txt",ios::in);
	
	if(archivo.fail()){
		cout<<"No se puede abrir el archivo";
		exit(1);
	}
	cout<<"=======================Texto Desencriptado===================================="<<endl;
	while(!archivo.eof()){
		getline(archivo,frase);
		
		while(frase[i] != '\0'){
			frase[i] = frase[i]-12+4;
			i++;
		}
		i=0;
		cout<< frase <<endl;	
	}
	cout<<"=======================Texto Desencriptado===================================="<<endl;
	archivo.close();
}

void desencriptarEspecifico(){
	
	string frase;
	int i=0;
	
	cout<<"Ingrese texto encriptado para desencriptar"<<endl;
	cin>>frase;
	
	while(frase[i] !='\0'){
		frase[i] = frase[i]-12+4;
		i++;
	}
	i=0;
	cout<<"\n===========================Texto desencriptado================================="<<endl;
	cout<<frase<<endl;
	cout<<"===========================Texto desencriptado================================="<<endl<<endl;
	
}

void mostrar(){
	ifstream archivo;
	string frase;
	archivo.open("archivoEncriptado.txt",ios::in);

	
	if(archivo.fail()){
		cout<<"No se puede abrir el archivo";
		exit(1);
	}
		cout<<"\n===========================Texto Encriptado================================="<<endl;
		while(!archivo.eof()){
			getline(archivo,frase);
			cout<<frase<<endl;
		}
		cout<<"===========================Texto Encriptado================================="<<endl<<endl;
	archivo.close();
}

















