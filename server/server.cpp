#include "SimpleTcpServer.h"
#include <iostream>
#include <cstring>

// Data handler callback fonksiyonu: Gelen veriyi ekrana yazdırır ve echo yapar.
void myDataHandler(int clientSocket, const char* data, int length, void* userData)
{
    SimpleTcpServer* server = static_cast<SimpleTcpServer*>(userData);

    std::cout << "Received from client " << clientSocket << ": " 
              << data << " Length: " << length << std::endl;
    if (strcmp(data, "QUIT\n") == 0)
    {
        server->stop();
    }
    
    // Gelen veriyi client'a geri gönder (echo).
    server->send(clientSocket, "Mesaj Alındı :))\n");
}


int main() {
    SimpleTcpServer server;
    // Data handler callback'ini ayarla. Burada handlerUserData olarak &server'ı geçiyoruz.
    server.setDataHandler(myDataHandler, &server);
    
    // "6667" portunu kullanıyoruz (IRC için varsayılan port gibi).
    if (server.start("127.0.0.1","6667") != 0) {
        std::cerr << "Failed to start server." << std::endl;
        return 1;
    }
    server.run();
    

    server.stop();
    return 0;
}
