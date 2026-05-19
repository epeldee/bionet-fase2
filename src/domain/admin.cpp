/*
 * admin.cpp
 *
 *  Created on: 19 may 2026
 *      Author: nahia.epelde
 */

#include "admin.h"
#include "usuario.h"
#include "../sockets/clienteSocket.h"
#include <iostream>
using namespace std;

Administrador::Administrador(string usuario, string contrasena)
	: Usuario(usuario, "Administrador", "", contrasena, "admin") {}

void Administrador::gestionCentros(){
    int op = -1;
    string nombre, dir, cp, mun, hor, tipo, tel, id;
    while (op != 0) {
        cout << "\n--- GESTION DE CENTROS DE SALUD ---\n";
        cout << "[1] Añadir centro\n[2] Modificar centro\n[3] Eliminar centro\n[0] Volver\n";
        cout << "Opcion: "; cin >> op; cin.ignore();

        ClienteSocket sock;
        switch (op) {
            case 1:
                cout << "Nombre: ";    getline(cin, nombre);
                cout << "Direccion: "; getline(cin, dir);
                cout << "CP: ";        getline(cin, cp);
                cout << "Municipio: "; getline(cin, mun);
                cout << "Horario: ";   getline(cin, hor);
                cout << "Tipo: ";      getline(cin, tipo);
                cout << "Telefono: ";  getline(cin, tel);
                cout << sock.enviar("ADMIN_ADD_CENTRO;" + nombre + ";" + dir + ";" +
                                     cp + ";" + mun + ";" + hor + ";" + tipo + ";" + tel) << "\n";
                break;
            case 2:
                cout << "ID del centro: "; getline(cin, id);
                cout << "Nuevo nombre: ";  getline(cin, nombre);
                cout << sock.enviar("ADMIN_MOD_CENTRO;" + id + ";" + nombre) << "\n";
                break;
            case 3:
                cout << "ID del centro: "; getline(cin, id);
                cout << sock.enviar("ADMIN_DEL_CENTRO;" + id) << "\n";
                break;
            case 0: break;
            default: cout << "Opcion no valida.\n";
        }
    }
}

void Administrador::gestionFarmacias() {
    int op = -1;
    string nombre, dir, cp, mun, tel, id, guardia;
    while (op != 0) {
        cout << "\n--- GESTION DE FARMACIAS ---\n";
        cout << "[1] Añadir farmacia\n[2] Modificar farmacia\n[3] Eliminar farmacia\n[0] Volver\n";
        cout << "Opcion: "; cin >> op; cin.ignore();

        ClienteSocket sock;
        switch (op) {
            case 1:
                cout << "Nombre: ";    getline(cin, nombre);
                cout << "Direccion: "; getline(cin, dir);
                cout << "CP: ";        getline(cin, cp);
                cout << "Municipio: "; getline(cin, mun);
                cout << "Telefono: ";  getline(cin, tel);
                cout << "Guardia (1/0): "; getline(cin, guardia);
                cout << sock.enviar("ADMIN_ADD_FARMACIA;" + nombre + ";" + dir + ";" +
                                     cp + ";" + mun + ";" + tel + ";" + guardia) << "\n";
                break;
            case 2:
                cout << "ID farmacia: ";  getline(cin, id);
                cout << "Nuevo nombre: "; getline(cin, nombre);
                cout << "Nueva dir: ";    getline(cin, dir);
                cout << "Nuevo tel: ";    getline(cin, tel);
                cout << sock.enviar("ADMIN_MOD_FARMACIA;" + id + ";" + nombre + ";" + dir + ";" + tel) << "\n";
                break;
            case 3:
                cout << "ID farmacia: "; getline(cin, id);
                cout << sock.enviar("ADMIN_DEL_FARMACIA;" + id) << "\n";
                break;
            case 0: break;
            default: cout << "Opcion no valida.\n";
        }
    }
}

void Administrador::gestionUsuarios() {
    int op = -1;
    string dni, pass;
    while (op != 0) {
        cout << "\n--- GESTION DE USUARIOS ---\n";
        cout << "[1] Eliminar usuario\n[2] Modificar contrasena\n[0] Volver\n";
        cout << "Opcion: "; cin >> op; cin.ignore();

        ClienteSocket sock;
        switch (op) {
            case 1:
                cout << "DNI: "; getline(cin, dni);
                cout << sock.enviar("ADMIN_DEL_USUARIO;" + dni) << "\n";
                break;
            case 2:
                cout << "DNI: ";             getline(cin, dni);
                cout << "Nueva contrasena: "; getline(cin, pass);
                cout << sock.enviar("ADMIN_MOD_PASS;" + dni + ";" + pass) << "\n";
                break;
            case 0: break;
            default: cout << "Opcion no valida.\n";
        }
    }
}

void Administrador::gestionPersonal() {
    int op = -1;
    string nombre, especialidad, id_centro, id;
    while (op != 0) {
        cout << "\n--- GESTION DE PERSONAL MEDICO ---\n";
        cout << "[1] Dar de alta medico\n[2] Dar de baja medico\n[0] Volver\n";
        cout << "Opcion: "; cin >> op; cin.ignore();

        ClienteSocket sock;
        switch (op) {
            case 1:
                cout << "Nombre: ";       getline(cin, nombre);
                cout << "Especialidad: "; getline(cin, especialidad);
                cout << "ID Centro: ";    getline(cin, id_centro);
                cout << sock.enviar("ADMIN_ADD_MEDICO;" + nombre + ";" + especialidad + ";" + id_centro) << "\n";
                break;
            case 2:
                cout << "ID medico: "; getline(cin, id);
                cout << sock.enviar("ADMIN_DEL_MEDICO;" + id) << "\n";
                break;
            case 0: break;
            default: cout << "Opcion no valida.\n";
        }
    }
}

void Administrador::ver_logs_sistema(){
	int op = -1;
	ClienteSocket sock;

	while(op != 0){
		string respuesta = sock.enviar("VER_LOGS");

		cout << "====================================\n";
		cout << "     BIONET: LOGS DEL SISTEMA\n";
		cout << "====================================\n";
		cout << "CONTENIDO ACTUAL\n";
		cout << respuesta;
		cout << "\n";
		cout << "[1] Actualizar vista\n";
		cout << "[2] Eliminar todos los logs\n";
		cout << "[0] Volver al menu anterior\n";
		cout << "Seleccione una opcion: \n";
		cin >> op;
		cin.ignore();

		switch(op){
			case 1:
				cout << "Actualizando...\n\n";
				break;

			case 2: {
				char seguro;
				cout << "¿Seguro que desea vaciar el historial? (S/N): ";
				cin >> seguro;
				cin.ignore();

				if(seguro == 'S' || seguro == 's'){
					string resp_vaciar = sock.enviar("VACIAR_LOGS");
					if(resp_vaciar == "OK"){
						cout << "[OK] El historial se ha vaciado correctamente.\n\n";

					} else{
						cout << resp_vaciar << "\n\n";
					}
				} else{
					cout << "[INFO] Operación cancelada.\n\n";
				}
				break;
			}

			case 0:
				break;

			default:
				cout << "Opción no válida.\n\n";
				break;


		}
	}

}

void Administrador::configuracion(){
	int op = -1;
	string nuevo_valor;
	ClienteSocket sock;

	while(op != 0){
		cout << "====================================\n";
		cout << "     CONFIGURACIÓN\n";
		cout << "====================================\n";
		cout << "[1] Cambiar puerto de escucha\n";
		cout << "[2] Cambiar ruta Base de Datos\n";
		cout << "[3] Cambiar ruta de logs\n";
		cout << "[0] Volver al panel del administrador\n";
		cout << "Seleccione una opcion: \n";
		cin >> op;
		cin.ignore();

		switch(op){
			case 1:
				cout << "Introduzca el nuevo puerto de escucha: ";
				getline(cin, nuevo_valor);
				cout << "[" << sock.enviar("SET_CONFIG;PUERTO;" + nuevo_valor) << "]\n\n";
				break;

			case 2:
				cout << "Introduzca la nueva ruta de la Base de Datos: ";
				getline(cin, nuevo_valor);
				cout << "[" << sock.enviar("SET_CONFIG;DB;" + nuevo_valor) << "]\n\n";
				break;

			case 3:
				cout << "Introduzca la nueva ruta para ek archivo de logs: ";
				getline(cin, nuevo_valor);
				cout << "[" << sock.enviar("SET_CONFIG;LOGS;" + nuevo_valor) << "]\n\n";
				break;

			case 0:
				cout << "[Saliendo...] Volviendo al panel del administrador.\n";
				break;

			default:
				cout << "Opción no válida.\n\n";
				break;


		}
	}

}

void Administrador::mostrarMenu() {
    int opcion = -1;
    while (opcion != 0) {
        cout << "\n=========================================\n";
        cout << "    BIONET - PANEL DE ADMINISTRACION\n";
        cout << "=========================================\n";
        cout << "[1] Gestion de Centros de Salud\n";
        cout << "[2] Gestion de Farmacias\n";
        cout << "[3] Gestion de Usuarios\n";
        cout << "[4] Gestion de Personal Medico\n";
        cout << "[5] Ver logs del sistema\n";
        cout << "[6] Configuración\n";
        cout << "[0] Salir\n";
        cout << "-----------------------------------------\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: gestionCentros();   break;
            case 2: gestionFarmacias(); break;
            case 3: gestionUsuarios();  break;
            case 4: gestionPersonal();  break;
            case 5: ver_logs_sistema();  break;
            case 6: configuracion();  break;
            case 0: cout << "Volviendo al menu principal.\n"; break;
            default: cout << "Opcion no valida.\n"; break;
        }
    }
}
