/*
 * paciente.h
 *
 *  Created on: 18 may 2026
 *      Author: nahia.epelde
 */

#ifndef SRC_PACIENTE_H_
#define SRC_PACIENTE_H_

#include "usuario.h"
#include <string>
using namespace std;

class Paciente : public Usuario {
private:
	string municipio;
	string historialMedico;

public:
	Paciente(string dni, string nombre, string email,
			string contrasena, string municipio,
			string historialMedico);

	string getMunicipio() const;
	string getHistorialMedico() const;

	//ESTO HAY QUE CAMBIAR CUANDO HAGAMOS LO DE LOS SOCKETS
	void buscarFarmacias(string busqueda);
	void buscarCentros(string busqueda);
	void consultarStock(string nombreMed, string localidad);
	void verFichaMedica();
	void reservarCita();


	void mostrarMenu() override;
};



#endif /* SRC_PACIENTE_H_ */
