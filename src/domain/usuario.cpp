/*
 * usuario.cpp
 *
 *  Created on: 18 may 2026
 *      Author: nahia.epelde
 */

#include "usuario.h"


Usuario::Usuario(string dni, string nombre, string email,
		string contrasena, string tipo)
	: dni(dni), nombre(nombre), email(email),
	  contrasena(contrasena), tipo(tipo) {}


string Usuario::getDni() const {return dni;}
string Usuario::getNombre() const {return nombre;}
string Usuario::getEmail() const {return email;}
string Usuario::getTipo() const {return tipo;}
