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
using namespace std;

// TODO: cuando la compañera tenga el socket listo, estas funciones
// se comunicarán con el servidor para validar y registrar usuarios.
// De momento son stubs que crean objetos de prueba.

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

    // TODO: enviar al servidor -> "LOGIN;<dni>;<pass>"
    // y recibir los datos del paciente si es correcto
    // Por ahora creamos un paciente de prueba si el DNI no está vacío
    if (dni.empty()) {
        cout << "[!] DNI no puede estar vacio.\n";
        return nullptr;
    }

    cout << "[STUB] Validando credenciales con el servidor...\n";
    cout << "[INFO] Login real pendiente de conexion con el servidor.\n";

    // Paciente de prueba hasta que esté el socket
    return new Paciente(dni, "Usuario Prueba", "prueba@email.com",
                        pass, "Bilbao", "Sin historial");
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

    // TODO: enviar al servidor -> "REGISTRO;<dni>;<nombre>;<email>;<municipio>;<pass>;<historial>"
    cout << "[STUB] Enviando datos de registro al servidor...\n";
    cout << "[INFO] Registro real pendiente de conexion con el servidor.\n";
    cout << "[OK] Paciente registrado correctamente (stub).\n";
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
