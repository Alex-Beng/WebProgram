#include "json.hpp"
using json = nlohmann::json;

#include <winsock2.h>
#include <ws2tcpip.h>

#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        wprintf(L"WSAStartup failed with error: %ld\n", iResult);
        return 1;
    }
    //----------------------
    // Create a SOCKET for listening for
    // incoming connection requests.
    SOCKET ListenSocket;
    ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ListenSocket == INVALID_SOCKET) {
        wprintf(L"socket failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    //----------------------
    // The sockaddr_in structure specifies the address family,
    // IP address, and port for the socket that is being bound.
    sockaddr_in addrServer;
    addrServer.sin_family = AF_INET;
    addrServer.sin_addr.s_addr = htonl(INADDR_ANY); //实际上是0
    addrServer.sin_port = htons(666);


	//绑定套接字到一个IP地址和一个端口上
    if (bind(ListenSocket,(SOCKADDR *) & addrServer, sizeof (addrServer)) == SOCKET_ERROR) {
        wprintf(L"bind failed with error: %ld\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

	//将套接字设置为监听模式等待连接请求
	//----------------------
    // Listen for incoming connection requests.
    // on the created socket
    if (listen(ListenSocket, 1) == SOCKET_ERROR) {
        wprintf(L"listen failed with error: %ld\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    SOCKADDR_IN addrClient;
	int len=sizeof(SOCKADDR);
    while(1)
	{
		//请求到来后，接受连接请求，返回一个新的对应于此次连接的套接字
		SOCKET AcceptSocket=accept(ListenSocket,(SOCKADDR*)&addrClient,&len);
		if(AcceptSocket  == INVALID_SOCKET)break; //出错

		char recvBuf[10240];
		while(1){
			int count =recv(AcceptSocket ,recvBuf,10240,0);
			if(count==0)break;//被对方关闭
			if(count==SOCKET_ERROR)break;//错误count<0
			int sendCount,currentPosition=0;
			
			// printf("接收来自客户端%s的信息：%s\n",inet_ntoa(addrClient.sin_addr), recvBuf);
            string t_s(recvBuf, recvBuf+strlen(recvBuf));
            // cout<<t_s[t_s.length()-1]<<endl;
            t_s = t_s.substr(0, t_s.length()-1);
            cout<<t_s<<endl;
            auto j = json::parse(t_s);
            // cout<<j<<endl;
            
            json tj;
            tj["method"] = "hello";
            tj["chat list"] = {"fuck", "you"};
            tj["chat list"].push_back(j["user name"]);
            // cout<<tj.dump().length()<<endl;
            send(AcceptSocket, tj.dump().c_str(), tj.dump(4).length(), 0);
		}
		//结束连接
		closesocket(AcceptSocket);
	}

	closesocket(ListenSocket);
	WSACleanup();

    return 0;
}
