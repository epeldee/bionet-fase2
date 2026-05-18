/*
 * paciente.cpp
 *
 *  Created on: 18 may 2026
 *      Author: nahia.epelde
 */

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
	//TODO: enviar al servidor -<z "BUSCAR_FARMACIA;<busqueda>"
	cout << "[STUB] Buscando farmacias por: " << busqueda << "\n";
	cout << "[INFO] Funcionalidad pendiente de conexion con el servidor.\n";
}

void Paciente::buscarCentros(string busqueda){
    // TODO: enviar al servidor -> "BUSCAR_CENTRO;<busqueda>"
    cout << "[STUB] Buscando centros de salud por: " << busqueda << "\n";
    cout << "[INFO] Funcionalidad pendiente de conexion con el servidor.\n";
}

void Paciente::consultarStock(string nombreMed, string localidad) {
    // TODO: enviar al servidor -> "BUSCAR_MED;<nombreMed>;<localidad>"
    cout << "[STUB] Consultando stock de: " << nombreMed << " en " << localidad << "\n";
    cout << "[INFO] Funcionalidad pendiente de conexion con el servidor.\n";
}

void Paciente::verFichaMedica() {
    // TODO: enviar al servidor -> "FICHA_MEDICA;<dni>"
    cout << "[STUB] Solicitando ficha medica del paciente: " << dni << "\n";
    cout << "[INFO] Funcionalidad pendiente de conexion con el servidor.\n";
}

void Paciente::reservarCita() {
    // TODO: enviar al servidor -> "BUSCAR_MEDICOS;<especialidad>;<localidad>"
    //       y luego -> "RESERVAR_CITA;<dni>;<id_medico>;<fecha>;<hora>"
    cout << "[STUB] Iniciando proceso de reserva de cita...\n";
    cout << "[INFO] Funcionalidad pendiente de conexion con el servidor.\n";
}


void Paciente::mostrarMenu() {
	int opcion = -1;
	string input1, input2;

	while (opcion != 0) {
		cout << "\n==================================\n";
		cout << "   BIONET: GESTION DE SALUD\n";
		cout << "   Bienvenido/a, " << nombre << "\n";
		cout << "==================================\n";
		cout << "[1] Buscar Farmacias por CP o municipio\n";
		cout << "[2] Buscar Centros de Salud por CP o municipio\n";
		cout << "[3] Consultar stock de medicamento\n";
		cout << "[4] Ver mi ficha medica\n";
		cout << "[5] Reservar cita medica\n";
		cout << "[0] Salir\n";
		cout << "----------------------------------\n";
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
				cout << "Saliendo del sistema...\n";
				break;

			default:
				cout << "Opcion no valida.\n";
				break;
		}
	}
	}
