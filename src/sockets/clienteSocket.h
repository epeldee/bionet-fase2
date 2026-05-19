#ifndef SRC_CLIENTESOCKET_H_
#define SRC_CLIENTESOCKET_H_

#include <winsock2.h>
#include <string>
using namespace std;

#define SERVER_IP   "127.0.0.1"
#define SERVER_PORT  8080

class ClienteSocket {
private:
    SOCKET s;   // el socket, igual que la variable 's' del ejemplo de la profe

public:
    ClienteSocket();
    ~ClienteSocket();

    bool conectar();                        // hace el socket() + connect()
    void desconectar();                     // hace el closesocket()
    string enviar(const string& mensaje);   // hace el send() + recv()

};

#endif /* SRC_CLIENTESOCKET_H_ */
