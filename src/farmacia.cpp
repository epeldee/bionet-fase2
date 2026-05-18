/*
 * farmacia.cpp
 *
 *  Created on: 18 may 2026
 *      Author: nahia.epelde
 */


#include "farmacia.h"
#include <iostream>

Farmacia::Farmacia(int id, string nombre, string direccion,
		string telefono, int coigoPostal,
		string municipio, bool esGuardia)
	: id(id), nombre(nombre), direccion(direccion), telefono(telefono),
	  codigoPostal(codigoPostal), municipio(municipio), esGuardia(esGuardia) {}

int Farmacia::getId() const {return id;}
string Farmacia::getNombre() const {return nombre;}
string Farmacia::getDireccion() const {return direccion;}
string Farmacia::getTelefono() const {return telefono;}
int Farmacia::getCodigoPostal() const {return codigoPostal;}
string Farmacia::getMunicipio() const {return municipio;}
bool Farmacia::getEsGuardia() const {return esGuardia;}

void Farmacia::mostrar() const {
	cout << "------------------------------\n";
	cout << "Farmacia: " << nombre << "\n";
	cout << "Direccion: " << direccion << " (" << codigoPostal << " " << municipio << ")\n";
	cout << "Telefono: " << telefono << "\n";
	cout << "Guardia: " << (esGuardia ? "SI" : "NO") << "\n";
}
