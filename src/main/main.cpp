	/*
 * main.cpp
 *
 *  Created on: 18 may 2026
 *      Author: nahia.epelde
 */

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include "../domain/paciente.h"
#include "../sockets/clienteSocket.h"
#include "../domain/admin.h"
using namespace std;

void limpiarBuffer() {
    cin.ignore(1000, '\n');
}

Paciente* loginPaciente() {
    string dni, pass;

    cout << "\n=====================================\n";
    cout << "         ACCESO PACIENTES\n";
    cout << "=====================================\n";

    cout << "DNI: ";
    getline(cin, dni);

    cout << "Contrasena: ";
    getline(cin, pass);

    ClienteSocket sock;
    string respuesta = sock.enviar("LOGIN;" + dni + ";" + pass);

    if (respuesta.substr(0, 2) == "OK") {
	   stringstream ss(respuesta);
	   string token;
	   string partes[5];
	   int i = 0;
	   while (getline(ss, token, ';') && i < 5) {
		   partes[i++] = token;
	   }
	   // partes[0]=OK, [1]=dni, [2]=nombre, [3]=email, [4]=municipio
	   cout << "[OK] Bienvenido/a, " << partes[2] << "\n";
	   return new Paciente(partes[1], partes[2], partes[3], pass, partes[4], "");
    } else {
        cout << "[!] " << respuesta << "\n";
        return nullptr;
    }
}

Administrador* loginAdmin() {
    string usuario, pass;

    cout << "\n=====================================\n";
    cout << "       ACCESO ADMINISTRADOR\n";
    cout << "=====================================\n";

    cout << "Usuario: ";
    getline(cin, usuario);
    cout << "Contrasena: ";
    getline(cin, pass);

    if (usuario == "admin" && pass == "1234") {
        cout << "[OK] Acceso concedido.\n";
        return new Administrador(usuario, pass);
    } else {
        cout << "[!] Credenciales de administrador incorrectas.\n";
        return nullptr;
    }
}

void registrarPaciente() {
    string dni, nombre, email, pass, municipio, historial;

    cout << "\n====================================\n";
    cout << "     REGISTRO DE NUEVO PACIENTE\n";
    cout << "====================================\n";

    cout << "DNI: ";
    getline(cin, dni);

    cout << "Nombre Completo: ";
    getline(cin, nombre);

    cout << "Email: ";
    getline(cin, email);

    cout << "Municipio: ";
    getline(cin, municipio);

    cout << "Contrasena: ";
    getline(cin, pass);

    cout << "Historial medico breve (alergias, enfermedades...): ";
    getline(cin, historial);

    ClienteSocket sock;
    string respuesta = sock.enviar("REGISTRO;" + dni + ";" + nombre + ";" +
                                    email + ";" + municipio + ";" + pass + ";" + historial);
    cout << (respuesta == "OK" ? "[OK] Registrado." : "[ERROR] " + respuesta) << "\n";
}


int main() {
    int opcion = -1;

    while (opcion != 0) {
        cout << "\n==================================\n";
        cout << "      BIENVENIDO A BIONET\n";
        cout << "==================================\n";
        cout << "[1] Login Paciente\n";
        cout << "[2] Login Administrador\n";
        cout << "[3] Registrarse (Nuevo Paciente)\n";
        cout << "[0] Salir\n";
        cout << "Seleccione: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: {
                Paciente* paciente = loginPaciente();
                if (paciente != nullptr) {
                    paciente->mostrarMenu();
                    delete paciente;
                }
                break;
            }
            case 2: {
                Administrador* admin = loginAdmin();
                if (admin != nullptr) {
                    admin->mostrarMenu();
                    delete admin;
                }
                break;
            }
            case 3:
                registrarPaciente();
                break;
            case 0:
                cout << "[Saliendo...] Aplicacion cerrada.\n";
                break;
            default:
                cout << "Opcion no valida.\n";
                break;
        }
    }

    return 0;
}
