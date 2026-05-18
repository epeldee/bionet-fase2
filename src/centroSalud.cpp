/*
 * centroSalud.cpp
 *
 *  Created on: 18 may 2026
 *      Author: nahia.epelde
 */

#include "centroSalud.h"
#include <iostream>
using namespace std;

CentroSalud::CentroSalud(int id, string nombre, string direccion, string horario,
						string telefono, int codigoPostal, string municipio,
						string tipoCentro, bool tieneUrgencias)
	: id(id), nombre(nombre), direccion(direccion), horario(horario),
	  telefono(telefono), codigoPostal(codigoPostal), municipio(municipio),
	  tipoCentro(tipoCentro), tieneUrgencias(tieneUrgencias) {}

int CentroSalud::getId() const {return id;}
string CentroSalud::getNombre() const {return nombre;}
string CentroSalud::getDireccion() const {return direccion;}
string CentroSalud::getHorario() const {return horario;}
string CentroSalud::getTelefono() const {return telefono;}
int CentroSalud::getCodigoPostal() const {return codigoPostal;}
string CentroSalud::getMunicipio() const {return municipio;}
string CentroSalud::getTipoCentro() const {return tipoCentro;}
bool CentroSalud::getTieneUrgencias() const {return tieneUrgencias;}

void CentroSalud::mostrar() const {
	cout << "------------------------------\n";
	cout << "Centro: " << nombre << " (" << tipoCentro << ")\n";
	cout << "Direccion: " << direccion << " (" << codigoPostal << " " << municipio << ")\n";
	cout << "Horario: " << horario << "\n";
	cout << "Telefono: " << telefono << "\n";
	cout << "Urgencias: " << (tieneUrgencias ? "SI" : "NO") << "\n";
}
