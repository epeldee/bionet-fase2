/*
 * main.cpp
 *
 *  Created on: 18 may 2026
 *      Author: nahia.epelde
 */

#include <stdio.h>
#include <iostream>
#include <string>
#include "Paciente.h"
#include "clienteSocket.h"
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
    if (respuesta == "OK") {
    } else {
        cout << "[!] " << respuesta << "\n";
        return nullptr;
    }
    return nullptr;
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
        cout << "[2] Registrarse (Nuevo Paciente)\n";
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

            case 2:
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
