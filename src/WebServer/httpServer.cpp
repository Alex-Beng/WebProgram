#include "httpServer.h"
#include "httpParser.h"

std::string main_path;
std::string main_page;
std::map<std::string, std::string> page2data;


httpServer::httpServer(int port, size_t buf_size, std::string main_path_, std::string main_page_) {
    this->port = port;
    this->buf_size = buf_size;
    main_path = main_path_;
    main_page = main_page_;

    // read main page
    cout<<main_path+main_page<<endl;
    std::ifstream t(main_path+main_page);
    std::string str((std::istreambuf_iterator<char>(t)),  
                    std::istreambuf_iterator<char>()); 
    page2data["/"] = str;
    page2data[main_page] = str;
    page2data["/favicon.ico"] = "";
    

    WSADATA wsaData;
    if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr<<"server start up error"<<std::endl;
    }
}

void httpServer::run() {
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
        std::cerr<<"getaddrinfo() error"<<std::endl;
        return ;
    }
    listen_socket = socket(socket_props->ai_family, socket_props->ai_socktype, socket_props->ai_protocol);
    if(listen_socket == INVALID_SOCKET) {
        std::cerr<<"socket() error"<<std::endl;
        return ;
    }

    if(bind(listen_socket, socket_props->ai_addr, (int)socket_props->ai_addrlen) == SOCKET_ERROR) {
        closesocket(listen_socket);
        std::cerr<<"bind() error"<<std::endl;
        return ;
    }

    if(listen(listen_socket, SOMAXCONN) == SOCKET_ERROR) {
        closesocket(listen_socket);
        std::cerr<<"listen() error"<<std::endl;
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
        threads[client_socket] = std::thread(httpServer::clientHandler, client_socket, buf_size);
        threads[client_socket].join();
    }
}

void httpServer::clientHandler(SOCKET client_socket, size_t buffer_size) {
    // 因为在新的线程里面，所以需要每个线程一个parser
    httpParser parser;
    
    // receive
    int recvbuflen = buffer_size;
    char recvbuf[recvbuflen];
    int bytes_received;

    // send
    std::string response;
    std::string response_head;
    std::string response_body;

    // 检查是否连接正确
    sockaddr_in client_info;
    int client_info_len = sizeof(sockaddr_in);
    char *client_ip;
    if(getpeername(client_socket, (sockaddr*)(&client_info), &client_info_len) == SOCKET_ERROR) {
        goto cleanup;
    }
    client_ip = inet_ntoa(client_info.sin_addr);
    
    bytes_received = recv(client_socket, recvbuf, recvbuflen, 0);
    parser.process(recvbuf, bytes_received);

    // std::cout<<"ya: ";
    // std::cout<<parser.method<<endl<<parser.path<<endl<<parser.http_version<<endl;
    // 正常输出，网络&parser正常
    
    pageReader(parser.path);
    response_body = page2data[parser.path];
    response_head = "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html; charset=UTF-8\r\n"
        "Connection: keep-alive\r\n"
        "Content-Length: " + std::to_string(response_body.length()) + "\r\n\r\n";
    response = response_head+response_body;
    // cout<<response<<endl;
    send(client_socket, response.c_str(), strlen(response.c_str()), 0);
cleanup:
    closesocket(client_socket);
}

void httpServer::pageReader(string page) {
    
    if (page == "/") {// main page
        return ;
    }
    else {
        // check cache
        cout<<main_path+page<<endl;
        if (page2data.find(page) == page2data.end()) { // nop
            std::ifstream t(main_path+page);
            std::string str((std::istreambuf_iterator<char>(t)),  
                            std::istreambuf_iterator<char>()); 
            page2data[page] = str;
        }
        else {
            return ;
        }
    }
}