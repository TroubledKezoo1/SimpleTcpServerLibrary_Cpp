#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int sock_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int n;

    // Soket oluştur
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        std::cerr << "Soket oluşturulamadı." << std::endl;
        exit(1);
    }

    // Server adresini ayarla
    std::memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    // Server IP adresini belirle (localhost: 127.0.0.1)
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        std::cerr << "Geçersiz adres veya adres dönüştürme hatası." << std::endl;
        close(sock_fd);
        exit(1);
    }

    // Servera bağlan
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Bağlantı hatası." << std::endl;
        close(sock_fd);
        exit(1);
    }
    std::cout << "Servera bağlanıldı." << std::endl;

    // İletişim döngüsü: Kullanıcıdan mesaj al, gönder, cevap oku
    while (true) {
        std::cout << "Mesaj girin (q ile çıkış): ";
        std::cin.getline(buffer, BUFFER_SIZE);
        if (std::strcmp(buffer, "q") == 0) {
            break;
        }

        // Mesajı gönder
        n = write(sock_fd, buffer, std::strlen(buffer));
        if (n < 0) {
            std::cerr << "Sokete yazma hatası." << std::endl;
            break;
        }

        // Cevabı oku
        std::memset(buffer, 0, BUFFER_SIZE);
        n = read(sock_fd, buffer, BUFFER_SIZE - 1);
        if (n < 0) {
            std::cerr << "Soketten okuma hatası." << std::endl;
            break;
        } else if (n == 0) {
            std::cout << "Server bağlantıyı kapattı." << std::endl;
            break;
        }
        std::cout << "Server cevabı: " << buffer << std::endl;
    }

    close(sock_fd);
    return 0;
}
