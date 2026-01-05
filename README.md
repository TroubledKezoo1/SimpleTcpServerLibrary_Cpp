# SimpleTcpServerLibrary_Cpp

A simple and lightweight TCP server library written in C++ for building network applications.

## 📋 About The Project

SimpleTcpServerLibrary_Cpp is a C++ implementation of a TCP client-server architecture. This library provides an easy-to-use interface for creating TCP network applications with minimal setup.

## 🎯 Features

- **Simple TCP Server**: Easy-to-implement server architecture
- **Client Support**: Built-in client implementation
- **Cross-Platform**: Works on multiple operating systems
- **Lightweight**: Minimal dependencies and overhead
- **Modern C++**: Written using modern C++ standards

## 🛠️ Technologies Used

- **C++** (100%)
- Socket Programming
- Network I/O

## 📦 Installation

### Requirements

```bash
# C++ compiler with C++11 support or higher
g++ --version
```

### Compilation

```bash
# Compile the server
g++ -o server server/server.cpp -std=c++11

# Compile the client
g++ -o client client.cpp -std=c++11
```

## 💻 Usage

### Starting the Server

```bash
./server <port>
```

### Running the Client

```bash
./client <server_ip> <port>
```

### Example

```bash
# Terminal 1 - Start server on port 8080
./server 8080

# Terminal 2 - Connect client to localhost
./client 127.0.0.1 8080
```

## 🚀 Example Code

### Server Implementation

```cpp
#include "server/server.h"

int main() {
    // Create and start TCP server
    TcpServer server(8080);
    server.start();
    return 0;
}
```

### Client Implementation

```cpp
#include "client.h"

int main() {
    // Connect to TCP server
    TcpClient client("127.0.0.1", 8080);
    client.connect();
    return 0;
}
```

## 📚 Project Structure

```
SimpleTcpServerLibrary_Cpp/
├── server/           # Server implementation files
├── client.cpp        # Client implementation
└── README.md         # Documentation
```

## 🔧 Configuration

The library supports various configuration options:
- Port number selection
- Buffer size adjustment
- Connection timeout settings
- Maximum client connections

## 📝 License

This project is open source.

## 📧 Contact

Project Owner: TroubledKezoo1

Project Link: [https://github.com/TroubledKezoo1/SimpleTcpServerLibrary_Cpp](https://github.com/TroubledKezoo1/SimpleTcpServerLibrary_Cpp)