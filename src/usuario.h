/*
 * usuario.h
 *
 *  Created on: 18 may 2026
 *      Author: nahia.epelde
 */

#ifndef SRC_USUARIO_H_
#define SRC_USUARIO_H_

#include <string>
using namespace std;

class Usuario {
protected:
	string dni;
	string nombre;
	string email;
	string contrasena;
	string tipo;  //puede ser o paciente o administrador


public:
	Usuario(string dni, string nombre, string email,
			string contrasena, string tipo);

	string getDni() const;
	string getNombre() const;
	string getEmail() const;
	string getTipo() const;

	virtual void mostrarMenu() = 0;

	virtual ~Usuario() {}
};



#endif /* SRC_USUARIO_H_ */
