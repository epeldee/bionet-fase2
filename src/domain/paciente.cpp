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

string Paciente::getMunicipio() const { return municipio; }
string Paciente::getHistorialMedico() const { return historialMedico; }

void Paciente::buscarFarmacias(string busqueda) {
	ClienteSocket sock;
	cout << sock.enviar("BUSCAR_FARMACIA;" + busqueda) << endl;
}

void Paciente::buscarCentros(string busqueda) {
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
	const string especialidades[] = {
		"Medicina General",
		"Pediatria",
		"Cardiologia",
		"Traumatologia",
		"Dermatologia",
		"Oftalmologia",
		"Ginecologia",
		"Fisioterapia"
	};
	const int total = 8;

	// Mostrar lista de especialidades
	cout << "\n--- RESERVAR CITA MEDICA ---\n";
	cout << "Especialidades disponibles:\n";
	for (int i = 0; i < total; i++) {
		cout << " [" << (i + 1) << "] " << especialidades[i] << "\n";
	}

	int opEsp = -1;
	cout << "Seleccione el numero de la especialidad: ";
	cin >> opEsp;
	cin.ignore();

	if (opEsp < 1 || opEsp > total) {
		cout << "Opcion no valida. Volviendo al menu...\n";
		return;
	}

	string especialidadElegida = especialidades[opEsp - 1];
	string localidad, idMedico, fecha, hora;

	cout << "Introduce CP o Municipio: ";
	getline(cin, localidad);

	// Buscar médicos de esa especialidad en esa zona
	ClienteSocket sock;
	cout << sock.enviar("BUSCAR_MEDICOS;" + especialidadElegida + ";" + localidad) << endl;

	cout << "Introduzca el ID del medico elegido: ";
	getline(cin, idMedico);

	// Bucle para intentar con otra hora si la cita no está disponible
	bool exito = false;
	while (!exito) {
		cout << "\n--- FECHA Y HORA DE LA CITA ---\n";
		cout << "Fecha (AAAA-MM-DD): ";
		getline(cin, fecha);
		cout << "Hora (HH:MM): ";
		getline(cin, hora);

		ClienteSocket sock2;
		string respuesta = sock2.enviar("RESERVAR_CITA;" + dni + ";" + idMedico + ";" + fecha + ";" + hora);

		if (respuesta.substr(0, 2) == "OK") {
			cout << "[OK] ¡Cita reservada con exito!\n";
			exito = true;
		} else {
			cout << "[!] El medico ya tiene una cita a esa hora. Intente con otra.\n";
			cout << "¿Desea probar otra hora? (S/N): ";
			string resp;
			getline(cin, resp);
			if (resp == "N" || resp == "n") {
				cout << "Reserva cancelada. Volviendo al menu...\n";
				break;
			}
		}
	}
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
