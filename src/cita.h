/*
 * cita.h
 *
 *  Created on: 18 may 2026
 *      Author: nahia.epelde
 */

#ifndef SRC_CITA_H_
#define SRC_CITA_H_

#include <string>
using namespace std;

class Cita{
private:
	int id;
	string dniPaciente;
	int idMedico;
	string fecha;
	string hora;

public:
	Cita(int id, string dniPaciente, int idMedico,
			string fecha, string hora);

	int getId() const;
	string getDniPaciente() const;
	int getIdMedico() const;
	string getFecha() const;
	string getHora() const;

	void mostrar() const;
};


#endif /* SRC_CITA_H_ */
