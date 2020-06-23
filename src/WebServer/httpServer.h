#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <list>
#include <future>
#include <chrono>
#include <thread>
#include <sstream>
#include <fstream>
#include <map>
#include <unordered_map>
using namespace std;

#include <winsock2.h>
#include <ws2tcpip.h>

class httpServer {
private:
    int port;
    size_t buf_size;
    SOCKET listen_socket;
public:
    httpServer(int port, size_t buf_size, std::string main_path, std::string main_page);
    void run();
private:
    static void clientHandler(SOCKET client_socket, size_t buffer_size);
    static void pageReader(string page);
};

#endif