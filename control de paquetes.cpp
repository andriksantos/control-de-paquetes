/*!
 * Control de paquetes 
 * Copyright 2018 Andrick Santos Author
 * Licensed under the Creative Commons Attribution 4.0 Unported License. For
 * details, see https://creativecommons.org/licenses/by-nc-sa/4.0/
 * or https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode
*/

/*Aqui empieza nuestro programa*/

#include <iostream>
#include <string>

using namespace std;

class Cliente {
public:
	long long CodigoCliente;
    string nombre;
	string telefono;
	string correo;

	Cliente (){/*Constructor*/
		CodigoCliente = 0;
		nombre = "";
		telefono = "";
		correo = "";
	}

	void pedirDatosCliente (long long ACodigoCliente)
	{
		CodigoCliente = ACodigoCliente;
		cout <<"Ingrese el nombre del Cliente......: ";
		cin.ignore(100, '\n');
		getline(cin, nombre);
		cout <<"Digite el numero de Telefono.......: ";
		getline(cin, telefono);
		cout <<"Ingrese el correo electronico......: ";
		getline(cin, correo);
		cout<<endl;
		cout <<"| Sus datos se guardaron exitosamente |" << endl<<endl;
		system ("PAUSE");
	}

	void mostrarDatosCliente()
	{
		cout <<"Codigo......: " << CodigoCliente <<endl
			 <<"Nombre......: " << nombre 		 <<endl
			 <<"Telefono....: " << telefono 	 <<endl
			 <<"Correo......: " << correo 	 	 <<endl<<endl
			 <<"| Cliente Encontrado |"<<endl;
	}

};

class Paquete {
	public: 
		long long numeroRastreo;
		long long CodigoCliente;
		string descripcionPaquete;
		double pesoLibras;
		bool Entregado;

		Paquete(){//Constructor

			numeroRastreo = 0;
			CodigoCliente = 0;
			descripcionPaquete = "";
			pesoLibras = 0;
			Entregado = false;
		}

		void pedirDatosPaquete(long long AnumeroRastreo)
		{
			cout << "Ingrese el codigo del cliente.........: ";
			cin >>CodigoCliente;
			numeroRastreo = AnumeroRastreo;
			cout <<"Descripcion del paquete...............: ";
			cin.ignore(100, '\n');
			getline(cin, descripcionPaquete);
			cout <<"Ingrese el peso en Libras.............: ";
			cin >>pesoLibras;
			cout<<endl;
			cout <<"| Datos guardados exitosamente |" << endl<<endl;
			system ("PAUSE");
		}

		void mostrarDatosPaquete()
		{
			cout <<"Codigo del Cliente........: " << CodigoCliente 		 << endl
				 <<"Numero de Rastro..........: " << numeroRastreo 	 	 << endl
				 <<"Descripcion del Paquete...: " << descripcionPaquete  << endl
				 <<"Peso en Libras............: " << pesoLibras			 << endl<<endl
				 <<"| Paquete Encontrado |";
		}


};

const int MAX_CLIENTES = 3;
const int MAX_PAQUETES = MAX_CLIENTES * 3;

class UnahExpress {
public:
	int contadorClientes;
	int contadorPaquetes;

	Cliente clientes[MAX_CLIENTES];
	Paquete paquetes[MAX_PAQUETES];


	UnahExpress()//Constructor
	{
		contadorClientes = 0;
		contadorPaquetes = 0;
	}
    
	int buscarPaquete(long long numeroRastreo)
	{
		int ubicacion = -1;
		for (int i = 0; i < contadorPaquetes; i++)
		{
			if (numeroRastreo == paquetes[i].numeroRastreo){
			ubicacion = i;
			break;
		}
	}
	return ubicacion;
}

int buscarCodigo(long long CodigoCliente)
{
	int ubicacion = -1;
	for (int i = 0; i < contadorClientes; i++)
	{
		if (CodigoCliente == clientes[i].CodigoCliente){
			ubicacion = i;
			break;
		}
	}
	return ubicacion;
}
void registrarCliente(void)
{
	if (contadorClientes < MAX_CLIENTES)
	{
		long long CodigoCliente;
		system("CLS");
		cout<<"--------------------------------" <<endl
			<<"| Ingrese de Datos del cliente |" <<endl
			<<"--------------------------------" <<endl<<endl
			<< "Ingrese el codigo del cliente......: ";
		cin >> CodigoCliente;

		int ubicacion = buscarCodigo(CodigoCliente);
		if (ubicacion == -1){
			clientes[contadorClientes].pedirDatosCliente(CodigoCliente);
			contadorClientes++;
		} else {
			cout <<"| Clientes ya existe |"<<endl;
			system("PAUSE");
		
		}
	} else {
		cout <<" | No hay mas cupos disponibles |"<<endl
			 <<" Intente con otro cliente" <<endl;
		system("PAUSE");
	}
}

void registrarPaquete()
{
	if (contadorPaquetes < MAX_PAQUETES)
	{
		long long numeroRastreo;

		system("CLS");
			cout <<"-----------------------" << endl
				 <<"| Ingreso de Paquetes |" << endl
				 <<"-----------------------" << endl<<endl
				 <<"Codigo de Rastreo del Paquete.........: ";
			cin >> numeroRastreo;

		int ubicacion = buscarPaquete(numeroRastreo);
		if (ubicacion == -1){
			paquetes[contadorPaquetes].pedirDatosPaquete(numeroRastreo);
			contadorPaquetes++;
		} else {
			cout <<"| Paquete que usted ingreso ya existe |"<<endl;
			system("PAUSE");
		
		}
	} else {
		cout <<" | No hay mas cupos disponibles |";
		system("PAUSE");
	}
}

	int busquedanumeroRastreo(){
		
		int ubicacion;
		long long AnumeroRastreo;
		system("CLS");
		cout<<"----------------------------------" << endl
			<<"| Busqueda de Rastreo de Paquete |" << endl
			<<"----------------------------------" << endl<<endl;
		cout <<"Codigo de Rastreo....: ";
		cin >>AnumeroRastreo;
		
		ubicacion = buscarPaquete(AnumeroRastreo);
		
		if (ubicacion != -1){
			paquetes[ubicacion].mostrarDatosPaquete();
		}
		else{
			cout <<"| ERROR: Codigo de Rastreo No Existe |";
		}	system("PAUSE");
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
	
	enum Opciones {NUEVO_CLIENTE = 1, NUEVO_PAQUETE, ENTREGA_PAQUETE, BUSCAR_PAQUETE, LISTA_PAQUETES, SALIR, mensaje_salida};
    do {
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
        cin >> opcion;
		cout<<endl;
        
        if (opcion <=0 || opcion >=7) {
        	cout <<endl <<"*** ERROR -- Opcion Seleccionada No Existe ***" << endl << endl;
        	system ("PAUSE");
		}
		
        switch (opcion) {
        	
            case NUEVO_CLIENTE:
            	cin.ignore(100, '\n');
				express.registrarCliente();
                break;
                
            case NUEVO_PAQUETE:
				express.registrarPaquete();
                break;
                
			case ENTREGA_PAQUETE:

                break;
                
			case BUSCAR_PAQUETE:
				express.busquedanumeroRastreo();
				break;
                
            case LISTA_PAQUETES:
                break;
                
            case SALIR:
                express.mensaje_salida();
                break;
        }
    } while (opcion != SALIR);
    return 0;
}

