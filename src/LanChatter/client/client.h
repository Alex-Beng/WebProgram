#ifndef CLIENT_H
#define CLIENT_H

#include "json.hpp"
using json = nlohmann::json;

#include <winsock2.h>

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
#include <set>
using namespace std;


class client {
private:
    std::string user_name;
    std::string ip;
    USHORT port;

    SOCKET connect_socket;
    sockaddr_in server_addr;

    json chat_list;

public:
    client(std::string user_name, std::string ip, USHORT port);
    void run();

private:
    void sendPackage(json& msg);
    void getChatList();
    void createChatRoom();
    void createDirectChat();
};



#endif