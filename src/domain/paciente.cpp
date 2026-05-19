/*
 * paciente.cpp
 *
 *  Created on: 18 may 2026
 *      Author: nahia.epelde
 */
#include "../sockets/clienteSocket.h"
#include "paciente.h"
#include <iostream>

Paciente::Paciente(string dni, string nombre, string email,
		string contrasena, string municipio,
		string historialMedico)
	: Usuario(dni, nombre, email, contrasena, "paciente"),
	  municipio(municipio), historialMedico(historialMedico) {}

string Paciente::getMunicipio() const {return municipio;}
string Paciente::getHistorialMedico() const {return historialMedico; }

//HAY QUE PONER LAS LLAMADAS REALES AL SOCKET
void Paciente::buscarFarmacias(string busqueda){
	ClienteSocket sock;
	cout << sock.enviar("BUSCAR_FARMACIA;" + busqueda) << endl;
}

void Paciente::buscarCentros(string busqueda){
	ClienteSocket sock;
	cout << sock.enviar("BUSCAR_CENTRO;" + busqueda) << endl;
}

void Paciente::consultarStock(string nombreMed, string localidad) {
	ClienteSocket sock;
	cout << sock.enviar("BUSCAR_MED;" + nombreMed + ";" + localidad) << endl;
}

void Paciente::verFichaMedica() {
	ClienteSocket sock;
	cout << sock.enviar("FICHA_MEDICA;" + dni) << endl;
}

void Paciente::reservarCita() {
	// Primero buscar médicos, luego reservar — los inputs los pides aquí
	    string especialidad, localidad, idMedico, fecha, hora;
	    cout << "Especialidad: "; getline(cin, especialidad);
	    cout << "Municipio: ";    getline(cin, localidad);

	    ClienteSocket sock;
	    cout << sock.enviar("BUSCAR_MEDICOS;" + especialidad + ";" + localidad) << endl;

	    cout << "ID del médico: "; getline(cin, idMedico);
	    cout << "Fecha (YYYY-MM-DD): "; getline(cin, fecha);
	    cout << "Hora (HH:MM): ";       getline(cin, hora);

	    ClienteSocket sock2;
	    cout << sock2.enviar("RESERVAR_CITA;" + dni + ";" + idMedico + ";" + fecha + ";" + hora) << endl;
}


void Paciente::mostrarMenu() {
	int opcion = -1;
	string input1, input2;

	while (opcion != 0) {
		cout << "\n==================================" << endl;
		cout << "   BIONET: GESTION DE SALUD" << endl;
		cout << "   Bienvenido/a, " << nombre << endl;
		cout << "==================================" << endl;
		cout << "[1] Buscar Farmacias por CP o municipio" << endl;
		cout << "[2] Buscar Centros de Salud por CP o municipio" << endl;
		cout << "[3] Consultar stock de medicamento" << endl;
		cout << "[4] Ver mi ficha medica" << endl;
		cout << "[5] Reservar cita medica" << endl;
		cout << "[0] Salir" << endl;
		cout << "----------------------------------" << endl;
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		cin.ignore();

		switch (opcion) {
			case 1:
				cout << "Introduce CP o Municipio: ";
				getline(cin, input1);
				buscarFarmacias(input1);
				break;

			case 2:
				cout << "Introduce CP o Municipio: ";
				getline(cin, input1);
				buscarCentros(input1);
				break;

			case 3:
				cout << "Nombre del medicamento: ";
				getline(cin, input1);
				cout << "Introduce CP o Municipio para buscar cerca: ";
				getline(cin, input2);
				consultarStock(input1, input2);
				break;

			case 4:
				verFichaMedica();
				break;

			case 5:
				reservarCita();
				break;

			case 0:
				cout << "Saliendo del sistema..." << endl;
				break;

			default:
				cout << "Opcion no valida." << endl;
				break;
		}
	}
	}
