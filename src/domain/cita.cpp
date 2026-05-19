/*
 * cita.cpp
 *
 *  Created on: 18 may 2026
 *      Author: nahia.epelde
 */

#include "cita.h"
#include <iostream>

Cita::Cita(int id, string dniPaciente, int idMedico,
			string fecha, string hora)
	: id(id), dniPaciente(dniPaciente), idMedico(idMedico),
	  fecha(fecha), hora(hora) {}

int Cita::getId() const {return id;}
string Cita::getDniPaciente() const {return dniPaciente;}
int Cita::getIdMedico() const {return idMedico;}
string Cita::getFecha() const {return fecha;}
string Cita::getHora() const {return hora;}

void Cita::mostrar() const{
    cout << "------------------------------\n";
    cout << "Cita ID: " << id << "\n";
    cout << "Medico ID: " << idMedico << "\n";
    cout << "Fecha: " << fecha << " a las " << hora << "\n";
}
