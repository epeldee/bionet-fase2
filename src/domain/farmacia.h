/*
 * farmacia.h
 *
 *  Created on: 18 may 2026
 *      Author: nahia.epelde
 */

#ifndef SRC_FARMACIA_H_
#define SRC_FARMACIA_H_


#include <string>
using namespace std;

class Farmacia {
private:
	int id;
	string nombre;
	string direccion;
	string telefono;
	int codigoPostal;
	string municipio;
	bool esGuardia;

public:
	Farmacia(int id, string nombre, string direccion,
			string telefono, int codigoPostal,
			string municipio, bool esGuardia);

	int getId() const;
	string getNombre() const;
	string getDireccion() const;
	string getTelefono() const;
	int getCodigoPostal() const;
	string getMunicipio() const;
	bool getEsGuardia() const;

	void mostrar() const;
};



#endif /* SRC_FARMACIA_H_ */
