/*
 * medicamento.h
 *
 *  Created on: 18 may 2026
 *      Author: nahia.epelde
 */

#ifndef SRC_MEDICAMENTO_H_
#define SRC_MEDICAMENTO_H_

#include <string>
using namespace std;

class Medicamento{
private:
	int id;
	int idFarmacia;
	string nombre;
	string tipo;
	double precio;
	int unidades;

public:
	Medicamento(int id, int idFarmacia, string nombre,
			string tipo, double precio, int unidades);

	int getId() const;
	int getIDFarmacia() const;
	string getNombre() const;
	string getTipo() const;
	double getPrecio() const;
	int getUnidades() const;

	void mostrar() const;
};


#endif /* SRC_MEDICAMENTO_H_ */
