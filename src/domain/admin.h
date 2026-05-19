/*
 * admin.h
 *
 *  Created on: 19 may 2026
 *      Author: nahia.epelde
 */

#ifndef SRC_ADMIN_H_
#define SRC_ADMIN_H_

#include "usuario.h"
using namespace std;

class Administrador : public Usuario {
public:
	Administrador(string usuario, string contrasena);

	void gestionCentros();
	void gestionFarmacias();
	void gestionUsuarios();
	void gestionPersonal();
	void ver_logs_sistema();
	void configuracion();

	void mostrarMenu() override;
};



#endif /* SRC_ADMIN_H_ */
