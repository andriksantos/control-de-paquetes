/*
		PROYECTO DE LENGUAJE DE PROGRAMACION II
				 		UNAH-VS

		INTEGRANTES:	SIRLEY CRISTEL LOPEZ CUBAS 20152000729
						Jajaira Yulissa Domínguez Ramos 20152001729
		
		SECCION....:    1700.
*/
#include<iostream>
#include<string>
using namespace std;

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


};


int main(){
	UnahExpress express;
	int opcion;
	string mensajePregunta;

	enum Opciones {nuevo_cliente = 1, nuevo_paquete, entrega_paquete, buscar_paquete, lista_paquetes, salir};
	do{
	   system("CLS");
	   system("color F2");
	   cout<< " *********************************** " <<endl
	       << " *  Sistema de control de paquete  * " <<endl
		   << " *********************************** " <<endl
		   << " * 1- Registrar cliente            * " <<endl
		   << " * 2- Ingresar paquete             * " <<endl
		   << " * 3- Entregar paquete             * " <<endl
		   << " * 4- Buscar paquete               * " <<endl
		   << " * 5- Mostrar paquetes por cliente * " <<endl
		   << " * 6- Salir                        * " <<endl
		   << " *********************************** " <<endl
		   << " Ingrese su opcion [1-6]: ";
		cin>> opcion;

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
			/*case salir:
				if (!mensajePregunta("SALIR DEL SISTEMA \n Desea salir del sistema?")){
					opcion = -1;
				}
				break;
*/
			
		}
	}while (opcion != salir);
	return 0;


}
