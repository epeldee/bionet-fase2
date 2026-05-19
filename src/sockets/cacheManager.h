/*
 * cacheManager.h
 *
 *  Created on: 19 may 2026
 *      Author: i.sadoun
 */

#ifndef SRC_SOCKETS_CACHEMANAGER_H_
#define SRC_SOCKETS_CACHEMANAGER_H_

#include <string>
#include <map>
#include <vector>
#include "clienteSocket.h"
#include <iostream>
using namespace std;

class CacheManager {
private:
	static map<string, string> cacheConsultas;


public:
	static string consultarServidorConCache(const string& comando, const string& criterio){
		string claveCache = comando + ";" + criterio;

		//Buscamos si la consulta exacta ya se hizo antes
		if(cacheConsultas.find(claveCache) != cacheConsultas.end()){
			cout << "[CACHÉ] Recuperando respuesta desde la memoria local (0 peticiones de red)...." << endl;
			return cacheConsultas[claveCache];
		}

		//Si no está en memoria, instanciamos el socket y llamamos la petición remota
		cout << "[RED] Petición no encontrada en caché. Consultando al servidor..." << endl;
		ClienteSocket sock;
		string respuesta = sock.enviar(claveCache);

		//Si la respuesta es válida, la guardamos en el almacén antes de retornarla
		if(respuesta.substr(0, 5) != "ERROR"){
			cacheConsultas[claveCache] = respuesta;
		}

		return respuesta;
	}

	static void limpiarCache(){
		cacheConsultas.clear();
	}

};


#ifdef DEFINE_CACHE_MAP
map<string, string> CacheManager::cacheConsultas;
#endif

#endif /* SRC_SOCKETS_CACHEMANAGER_H_ */
