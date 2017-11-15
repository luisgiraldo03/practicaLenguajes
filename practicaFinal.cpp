#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>

using namespace std;

void menu(); //men� num�rico
void encriptar();//m�todo para encriptar el texto
void desencriptarTodo();//m�todo que desencripta toda la informaci�n del archivo de texto
void desencriptarEspecifico();//m�todo que desencripta un texto espec�fico
void mostrar();//m�todo que muestra toda la informaci�n encriptada

int main(){
	menu();
	return 0;
}

void menu(){
	int opcion;
	
	do{
		cout<<"1. ingresar texto para encriptar"<<endl
			<<"2. desencriptar todo el texto del archivo"<<endl
			<<"3. desencriptar texto espec�fico"<<endl
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
	
	archivo.open("archivo.txt",ios::app);//archivo de texto que guarda la informaci�n sin encriptar 
	archivoEncriptado.open("archivoEncriptado.txt",ios::app);//archivo que guarda la informaci�n encriptada
	
	if(archivo.fail()){//si el archivo falla
		cout<<"Error al abrir el archivo"<<endl;
		exit(1);//funci�n que se utiliza gracias a la librer�a stdlib.h
	}
	do{
		fflush(stdin);
		cout<<"Escriba texto para encriptar"<<endl;
		getline(cin, frase);
		int aux = frase.length();//asignamos a aux el tama�o de la frase
		char texto[aux];
		for(int i=0;i<frase.length(); i++){
			texto[i] = frase[i];//asignamos a la primera posici�n la primera letra de la palabra
		}
		archivo<<frase;//agregar texto sin encriptar al archivo
		archivo<<"\n";//agregar un salto de linea al texto
		
		while(texto[i] !='\0'){//mientras el texto sea diferente a vac�o
			texto[i] = texto[i]+12-4;//encriptamos cada palabra 
			archivoEncriptado<<texto[i];//guardamos la palabra en el archivo encriptado
			i++;//incrementamos i en 1;
		}
		i=0;
		archivoEncriptado<<"\n";//agregamos un salto de linea a el archivo encriptado
		cout<<"desea agregar otra frase? Si=(ingrese 's') No(Ingrese 'n')"<<endl;
		cin>>rpt;
	
		
	}while((rpt == 'S')||(rpt == 's'));
	archivo.close();//cerramos el archivo
	cout<<"\n============================================================="<<endl<<endl;
}

void desencriptarTodo(){
	ifstream archivo;
	string frase;
	int i=0;

	archivo.open("archivoEncriptado.txt",ios::in);//abrimos el archivo encriptado
	
	if(archivo.fail()){//si el archivo falla
		cout<<"No se puede abrir el archivo";
		exit(1);
	}
	cout<<"=======================Texto Desencriptado===================================="<<endl;
	while(!archivo.eof()){//minetras el archivo no est� vac�o
		getline(archivo,frase);
		
		while(frase[i] != '\0'){//recorremos el archivo encriptado
			frase[i] = frase[i]-12+4;//desencriptamos
			i++;
		}
		i=0;
		cout<< frase <<endl;//imprimimos 
	}
	cout<<"=======================Texto Desencriptado===================================="<<endl;
	archivo.close();//cerramos el archivo
}

void desencriptarEspecifico(){
	
	string frase;
	int i=0;
	
	cout<<"Ingrese texto encriptado para desencriptar"<<endl;
	cin>>frase;//escribimos (o copiamos) la frase encriptada
	
	while(frase[i] !='\0'){//recorremos las lineas
		frase[i] = frase[i]-12+4;//desencriptamos
		i++;
	}
	i=0;
	cout<<"\n===========================Texto desencriptado================================="<<endl;
	cout<<frase<<endl;//imprimimos el texto desencriptado
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
		while(!archivo.eof()){//mientras el archivo no este vac�o
			getline(archivo,frase);
			cout<<frase<<endl;//imprimimos las lineas del archivo
		}
		cout<<"===========================Texto Encriptado================================="<<endl<<endl;
	archivo.close();//cerramos el archivo
}

















