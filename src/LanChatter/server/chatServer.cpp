#include "chatServer.h"

std::map<std::string, SOCKET> name2socket;
std::map<std::string, std::vector<std::string>> gname2name;
std::map<std::string, std::vector<std::string>> name2gname;


chatServer::chatServer(USHORT port) {
    this->port = port;
    WSADATA wsaData;
    if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        throw std::runtime_error("server start up error");
    }
}

void chatServer::run() {
    // 智能指针+匿名函数
    std::shared_ptr<addrinfo> socket_props(nullptr, [](addrinfo* ai) { freeaddrinfo(ai); });
    addrinfo hints;
    ZeroMemory(&hints, sizeof(hints));

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    int addrinfo_status = getaddrinfo(NULL, std::to_string(port).c_str(), &hints, (addrinfo**)&socket_props);
    if(addrinfo_status != 0) {
        throw std::runtime_error("getaddrinfo() error");
        return ;
    }
    listen_socket = socket(socket_props->ai_family, socket_props->ai_socktype, socket_props->ai_protocol);
    if(listen_socket == INVALID_SOCKET) {
        throw std::runtime_error("socket() error");
        return ;
    }

    if(bind(listen_socket, socket_props->ai_addr, (int)socket_props->ai_addrlen) == SOCKET_ERROR) {
        closesocket(listen_socket);
        throw std::runtime_error("bind() error");
        return ;
    }

    if(listen(listen_socket, SOMAXCONN) == SOCKET_ERROR) {
        closesocket(listen_socket);
        throw std::runtime_error("listen() error");
        return ;
    }

    std::map<SOCKET, std::thread> threads;
    while (1) {
        SOCKET client_socket;
        try {
            client_socket = accept(listen_socket, NULL, NULL);
            if(client_socket == INVALID_SOCKET) {
                throw std::runtime_error(std::to_string(WSAGetLastError()));
            }
        } catch(std::runtime_error &e) {
            std::cerr<<e.what()<<endl;
            continue;
        }
        cout<<"new client!"<<endl;
        threads[client_socket] = std::thread(chatServer::clientHandler, client_socket);
        // threads[client_socket].join();
    }


}

void chatServer::clientHandler(SOCKET client_socket) {

    int recvbuflen = 10240;
    char recvbuf[recvbuflen];
    int bytes_received;
    string t_s;
    json j;
    std::string user_name;

    map<string, SOCKET>::iterator item;
    
    // 检查是否连接正确
    sockaddr_in client_info;
    int client_info_len = sizeof(sockaddr_in);
    char *client_ip;
    if(getpeername(client_socket, (sockaddr*)(&client_info), &client_info_len) == SOCKET_ERROR) {
        goto cleanup;
    }
    
    // 第一次需要得到user name
    memset(recvbuf, 0, sizeof(recvbuf));
    bytes_received = recv(client_socket, recvbuf, recvbuflen, 0);
    if (bytes_received <= 0) {
        throw std::runtime_error(std::to_string(WSAGetLastError()));
    }
    
    t_s = string(recvbuf, recvbuf+strlen(recvbuf));
    cout<<t_s<<endl;
    j = json::parse(t_s);
    // check method
    if (j["method"] != "hello") {
        throw std::runtime_error("unexpect client!");
    }
    user_name = j["user name"];
    
    
    // check user name usablility
    item = name2socket.find(user_name);
    if (item == name2socket.end()) {
        // 莫得，可用
        name2socket[user_name] = client_socket;
        // give user chat list
        j.clear();
        j["method"] = "hello";
        for (auto& kv : name2socket) {// c++20 safe 🙂
            j["chat list"].push_back(kv.first);
        }
        for (auto& kv : name2socket) {
            // 查找user在的群
            for (auto& gn : name2gname[kv.first]) {
                j["chat list"].push_back(gn);
            }
            send(kv.second, j.dump().c_str(), j.dump().length(), 0);
        }
    }
    else {
        // 给爷爬
        j.clear();
        j["method"] = "hello";
        j["fuck off"] = true;
        send(client_socket, j.dump().c_str(), j.dump().length(), 0);
        Sleep(10000);
        goto cleanup;
    }

    while (1) {
        memset(recvbuf, 0, sizeof(recvbuf));
        int count =recv(client_socket, recvbuf, 10240, 0);
        if (count <= 0) {
            goto cleanup;   
        }

        // else get msg from client
        t_s = string(recvbuf, recvbuf+strlen(recvbuf));
        cout<<t_s<<endl;
        j.clear();
        j = json::parse(t_s);
        std::string method = j["method"];
        if (method == "hello") { // nothing to do
            continue;
        }
        else if (method == "message" || method == "file" || method == "file respond") {
            std::string receiver = j["receiver"];
            j["sender"] = user_name;

            auto find_res = name2socket.find(receiver);
            if (find_res == name2socket.end()) {// group
                auto gfind_res = gname2name.find(receiver);
                for (auto& gname : gfind_res->second) {
                    send(name2socket[gname], j.dump().c_str(), j.dump().length(), 0);
                }
            }
            else {
                send(name2socket[receiver], j.dump().c_str(), j.dump().length(), 0);
            }

        }
        else if (method == "new group") {
            // 创建映射
            std::string gname = j["group name"];
            std::vector<std::string> g_user_names;
            for (int i=0; i<j["group members"].size(); i++) {
                std::string tname;
                j["group members"][i].get_to<std::string>(tname);
                g_user_names.push_back(tname);
            }
            gname2name[gname] = g_user_names;
            name2gname[user_name].push_back(gname);
            
            // 告诉所所有在群用户
            j.clear();
            j["method"] = "hello";
            for (auto& kv : name2socket) {
                j["chat list"].push_back(kv.first);
            }
            j["chat list"].push_back(gname);
            for (auto& receiver : gname2name[gname]) {
                send(name2socket[receiver], j.dump().c_str(), j.dump().length(), 0);
            }
        }
    }
    
cleanup:
    // delete from map
    item = name2socket.find(user_name);
    name2socket.erase(item);
    // tell all left users
    j.clear();
    j["method"] = "hello";
    for (auto& kv : name2socket) {
        j["chat list"].push_back(kv.first);
    }
    for (auto& kv : name2socket) {
        send(kv.second, j.dump().c_str(), j.dump().length(), 0);
    }    
    closesocket(client_socket);
}
