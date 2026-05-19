/*
 * medicamento.cpp
 *
 *  Created on: 18 may 2026
 *      Author: nahia.epelde
 */

#include "medicamento.h"
#include <iostream>
#include <iomanip>

Medicamento::Medicamento(int id, int idFarmacia, string nombre,
						string tipo, double precio, int unidades)
	: id(id), idFarmacia(idFarmacia), nombre(nombre),
	  tipo(tipo), precio(precio), unidades(unidades) {}

int Medicamento::getId() const {return id;}
int Medicamento::getIDFarmacia() const {return idFarmacia;}
string Medicamento::getNombre() const {return nombre;}
string Medicamento::getTipo() const {return tipo;}
double Medicamento::getPrecio() const {return precio;}
int Medicamento::getUnidades() const {return unidades;}

void Medicamento::mostrar() const{
	cout << "------------------------------\n";
	cout << "Medicamento: " << nombre << " (" << tipo << ")\n";
	cout << "Precio: " << precio << " EUR\n";
	cout << "Unidades disponibles: " << unidades << "\n";
}
