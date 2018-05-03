/*
				PROYECTO DE LENGUAJE DE PROGRAMACION II
					 		UNAH-VS

		PROYECTO...:	CONTROL DE PAQUETES.

		INTEGRANTES:	SIRLEY CRISTEL LOPEZ CUBAS			20152000729.
						Jajaira Yulissa Dominguez Ramos		20152001729.
		
		SECCION....:    1700.
*/
/*Aqui empieza nuestro programa*/
#include<iostream>
#include<string>
using namespace std;
/*Definicion de la clase*/
class UnahExpress{
public:

	void nuevoCliente(){

	}

	void nuevoPaquete(){

	}

	void entregaPaquete(){

	}

	void buscarPaquete(){

	}

	void listaPaquetePorCliente(){

	}

	void mensaje_salida(){
		cout<<"Gracias por usar nuestro servicio."	<<endl
			<<"Que tenga un buen dia..."			<<endl<<endl
			<<"Precione nuevamente ENTER para salir."<<endl;
	}

};


int main(){
	UnahExpress express;
	int opcion;

	enum Opciones {nuevo_cliente = 1, nuevo_paquete, entrega_paquete, buscar_paquete, lista_paquetes, salir,mensaje_salida};
	do{
	   system("CLS");
	   system("color F2");
	   cout<< " ------------------------------------ " <<endl
	       << " |  Sistema de control de paquetes  | " <<endl
		   << " ------------------------------------ " <<endl
		   << " | 1.- Registrar cliente            | " <<endl
		   << " | 2.- Ingresar paquete             | " <<endl
		   << " | 3.- Entregar paquete             | " <<endl
		   << " | 4.- Buscar paquete               | " <<endl
		   << " | 5.- Mostrar paquetes por cliente | " <<endl
		   << " | 6.- Salir                        | " <<endl
		   << " ------------------------------------ " <<endl
		   << " Ingrese su opcion [1-6]: ";
		cin>> opcion;
		cout<<endl;

		switch(opcion){
			case nuevo_cliente:
				express.nuevoCliente();
				break;
			case nuevo_paquete:
				express.nuevoPaquete();
				break;
			case entrega_paquete:
				express.entregaPaquete();
				break;
			case buscar_paquete:
				express.buscarPaquete();
				break;
			case lista_paquetes:
				express.listaPaquetePorCliente();
				break;
			case salir:
				express.mensaje_salida();
				break;
			
		}
	}while (opcion != salir);
	return 0;


}

