#ifndef CHATSERVER_H
#define CHATSERVER_H

#include "json.hpp"
using json = nlohmann::json;

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
using namespace std;

#include <winsock2.h>
#include <ws2tcpip.h>


class chatServer {
private:
    USHORT port;
    SOCKET listen_socket;
public:
    chatServer(USHORT);
    void run();
private:
    static void clientHandler(SOCKET client_socket);
};

#endif