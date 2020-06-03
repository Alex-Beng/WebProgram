#include "client.h"

client::client(std::string user_name, std::string ip, USHORT port) {
    this->user_name = user_name;
    this->ip = ip;
    this->port = port;

    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        throw std::runtime_error(std::to_string(WSAGetLastError()));
    }

    connect_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (connect_socket == INVALID_SOCKET) {
        throw std::runtime_error(std::to_string(WSAGetLastError()));
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());
    server_addr.sin_port = htons(port);

    iResult = connect( connect_socket, (SOCKADDR*) &server_addr, sizeof(server_addr));
    if ( iResult == SOCKET_ERROR) {
        closesocket(connect_socket);
        cerr<<"Fail to connect server"<<endl;
        throw std::runtime_error(std::to_string(WSAGetLastError()));
    }
}

void client::run() {
    enum {SELECTTING, CHATTING};
    int status = SELECTTING;
    string chat_room_str;
    int chat_room;
    while (1) {
        switch (status) {
        case SELECTTING:
            getChatList();
            printf("select chat room: [num] for room num; default broadcast");
            
            getline(cin, chat_room_str);
            chat_room = atoi(chat_room_str.c_str());
            
            status = CHATTING;
            break;
        case CHATTING:
            
            break;
        }        
    }

}  

void client::sendPackage(json& msg) {
    std::string s = msg.dump();
    send(this->connect_socket, s.c_str(), s.length(), 0);
}

void client::getChatList() {
    // tell server who i am
    json hello_msg;
    hello_msg["user name"] = this->user_name;
    hello_msg["method"] = "hello";
    sendPackage(hello_msg);

    // update users in lan
    char recv_buf[2048];
    int count =recv(connect_socket, recv_buf, 2048, 0);
    if(count<=0) {
        cerr<<"connection died suddenly"<<endl;
        throw std::runtime_error(std::to_string(WSAGetLastError()));
    }
    string t_s(recv_buf);
    auto j = json::parse(t_s);
    if (! j["chat list"].is_array()) {
        cerr<<"[chat list] expecting array"<<endl;
        throw std::runtime_error("[chat list] expecting array");
    }
    chat_list = j["chat list"];

    printf("current available user: \n");
    chat_list.dump();
    for (int i=0; i<chat_list.size(); i++) {
        std::string ts;
        chat_list[i].get_to<std::string>(ts);

        if (ts != user_name)
            printf("\t %d %s\n", i+1, ts.c_str());
    }

}