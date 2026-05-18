#include "clienteSocket.h"
#include <iostream>
#include <cstring>
using namespace std;

ClienteSocket::ClienteSocket() : s(INVALID_SOCKET) {}

ClienteSocket::~ClienteSocket() {
	desconectar();
}

bool ClienteSocket::conectar() {
	WSADATA wsaData;
	struct sockaddr_in server;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		cerr << "WSAStartup failed: " << WSAGetLastError() << endl;
		return false;
	}

	// SOCKET creation
	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s == INVALID_SOCKET) {
		cerr << "Error al crear socket: " << WSAGetLastError() << endl;
		WSACleanup();
		return false;
	}

    server.sin_addr.s_addr = inet_addr(SERVER_IP);
	server.sin_family      = AF_INET;
	server.sin_port        = htons(SERVER_PORT);

  // CONNECT to remote server  (igual que el ejemplo)
  if (connect(s, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {
	  cerr << "Error de conexion: " << WSAGetLastError() << endl;
	  closesocket(s);
	  WSACleanup();
	  s = INVALID_SOCKET;
	  return false;
  }
  return true;
}

void ClienteSocket::desconectar() {
	if (s != INVALID_SOCKET) {
		closesocket(s);
		WSACleanup();
		s = INVALID_SOCKET;
	}
}
string ClienteSocket::enviar(const string& mensaje) {
    if (!conectar()) return "ERROR;Sin conexion";

    char sendBuff[512] = {};
    char recvBuff[512] = {};

    // SEND  (igual que el ejemplo)
    strncpy(sendBuff, mensaje.c_str(), sizeof(sendBuff) - 1);
    send(s, sendBuff, sizeof(sendBuff), 0);

    // RECEIVE  (igual que el ejemplo)
    int bytes = recv(s, recvBuff, sizeof(recvBuff) - 1, 0);

    desconectar();
    return (bytes > 0) ? string(recvBuff) : "ERROR;Sin respuesta";
}

