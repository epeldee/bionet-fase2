/*
 * centroSalud.h
 *
 *  Created on: 18 may 2026
 *      Author: nahia.epelde
 */

#ifndef SRC_CENTROSALUD_H_
#define SRC_CENTROSALUD_H_

#include <string>
using namespace std;

class CentroSalud {
private:
	int id;
	string nombre;
	string direccion;
	string horario;
	string telefono;
	int codigoPostal;
	string municipio;
	string tipoCentro;
	bool tieneUrgencias;

public:
	CentroSalud(int id, string nombre, string direccion, string horario,
				string telefono, int codigoPostal, string municipio,
				string tipoCentro, bool tieneUrgencias);

	int getId() const;
	string getNombre() const;
	string getDireccion() const;
	string getHorario() const;
	string getTelefono() const;
	int getCodigoPostal() const;
	string getMunicipio() const;
	string getTipoCentro() const;
	bool getTieneUrgencias() const;

	void mostrar() const;
};



#endif /* SRC_CENTROSALUD_H_ */
