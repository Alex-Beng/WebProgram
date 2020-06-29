# 知识点

Socket 概念

Socket 编程思路

winsock 编程思路

socket 编程常用API函数和数据结构

# 重点

winsock 函数用法

# 什么是Socket

**进程**从网络中**接收数据/向网络发送数据**都是通过它的套接字来进行。

套接字是主机内 **应用层和传输层的接口**，也称为程序和网络之间的api。

socket和文件句柄一样，是**操作系统的资源**。

## 好处

屏蔽了复杂的**网络操作**，通信过程交由操作系统处理。

降低程序员的**开发难度**，只需要关注应用层的业务逻辑

提高了软件的**开发效率**，编码和调试工作量大大减少。

## socket 编程规范

Berkeley socket 

Windows socket

## socket 类型

### 字节流套接字 stream socket

TCP 协议。面向连接、无差错的、发送先后顺序一致的、非重复的网络数据传输。

### 数据包套接字 datagram socket

UDP 协议。无连接的服务，相互独立的数据连接。

### 原始套接字 raw socket

提供对网络下层通信协议（例如ip协议）的直接访问，课用于开发新协议/特定网络功能。

# winsock 库

.h 声明函数接口 **编译时必须**

.lib 函数执行的代码在那个dll，dll中的什么位置 **链接时必须**

.dll 函数可执行代码 **运行时必须**


## 使用流程

1. WSAStartup() 完成初始化（注册）
   
   ```cpp
    int WSAStartup   (
        WORD wVersionRequested, // 高字节主版本号，低字节副版本号
        LPWSADATA lpWSAData     // 用于返回dll库的信息
    );

    // 返回的 WSADATA 结构
    typedef struct WSAData {
        WORD	wVersion;   	// 库文件建议应用程序使用的版本
        WORD	wHighVersion;   	 // 库文件支持的最高版本
        char	szDescription[WSADESCRIPTION_LEN+1];  // 库描述字符串
        char	szSystemStatus[WSASYS_STATUS_LEN+1];  // 系统状态字符串
        unsigned short	iMaxSockets;       // 同时支持的最大套接字的数量
        unsigned short	iMaxUdpDg;       // 2.0版中已废弃的参数
        char  *		lpVendorInfo;       // 2.0版中已废弃的参数
    } WSADATA,  * LPWSADATA;

    // 返回值
    /*
    成功：返回0。
    失败：返回错误代码。
    WSASYSNOTREADY（网络系统未准备好）
    WSAVERNOTSUPPORTED（版本不支持）
    WSAEINPROGRESS（正在执行一个阻塞的操作）
    WSAEFAULT（指针lpWSAData不合法）
    */

    ```

    做了
    1. 查找dll文件
    2. 检查dll版本
    3. 将dll与程序绑定
    4. 成功返回通过lpwsadata返回dll信息
2. 创建套接字
3. 绑定套接字到指定的IP地址和端口号
4. 设置套接字进入监听状态
5. 接受连接请求
6. 发送/接收数据
7. 关闭套接字
8. WSACleanup() 注销函数

    函数定义
    ```cpp
    int  WSACleanup (void);

    // 返回值
    /*
    成功：返回0
    失败：返回SOCKET_ERROR
    ```

    做了
    1. 中止对dll的调用，释放引用动态链接库时占用的系统资源

    **WSAStartup和WSACleanup必须成对使用**


## 寻址方式和字节顺序

### 使用sockaddr结构体解决兼容问题。

```cpp

struct sockaddr {
	u_short sa_family;      // 地址家族
	char	sa_data[14];    // 不同家族中不一样
};

```

### sockaddr 的TCP/IP版本

```cpp
struct sockaddr_in {
	short		sin_family;     // AF_INET
	u_short 	sin_port;       // 端口
	struct in_addr 	sin_addr;   // ipv4地址
	char		sin_zero[8];    // 补齐
};
```

#### ipv4地址存储方式

```cpp
struct in_addr {
	union {
		struct { u_char s_b1,s_b2,s_b3,s_b4; } S_un_b;
		struct { u_short s_w1,s_w2; } S_un_w;
		u_long S_addr;
	} S_un;
    #define s_addr  S_un.S_addr     /* can be used for most tcp & ip code */
    #define s_host  S_un.S_un_b.s_b2		/* host on imp */
    #define s_net   S_un.S_un_b.s_b1		 /* network */
    #define s_imp   S_un.S_un_w.s_w2		/* imp */
    #define s_impno S_un.S_un_b.s_b4		/* imp # */
    #define s_lh    S_un.S_un_b.s_b3		 /* logical host */
}
```

可为一个32位int/两个16位字/四个8位字节

##### in_addr初始化方式

```cpp
unsigned long inet_addr( const char* cp );  // str -> int
char*  inet_ntoa( struct in_addr in );      // int -> str

```

### 字节顺序统一用网络字节顺序（大端模式）（除了sin_family，不是协议的一部分）

### 字节序转换函数

```cpp
// host to net short/
u_short htons( u_short hostshort );
u_long htonl( u_long hostlong );
u_short ntohs( u_short netshort );
u_long ntohl( u_long netlong );

```


## 套接字创捷和关闭

### 创建

```cpp
SOCKET socket(
   int af,   	 	// 地址族，WinSock只支持AF_INET(那你吹那么多？)
   int type, 	    // 用来指定套接字的类型（流/数据报/原始）
   int protocol 	// 指定使用的协议，如IPPROTO_TCP); 
```

当type参数指定为SOCK_STREAM和SOCK_DGRAM时，系统已经明确使用TCP和UDP来工作，所以protocol参数可以指定为0。

### 关闭

```cpp
int closesocket(SOCKET s); 	// 参数是要关闭的套接字的句柄 

// 没有错误发生，函数返回0，否则返回SOCKET_ERROR
```

## 应用程序与IP和端口如何关联？

通过绑定套接字到指定IP和端口

使用bind函数
```cpp
int bind (
    SOCKET s,
    const struct sockaddr *  name,
    int namelen
);
/*
返回值
成功：返回0
失败：返回SOCKET_ERROR
*/
```

1. connect()或listen()函数前调用。
2. 服务端listen监听的套接字必须绑定
3. 客户端一般不必绑定，除非要指定使用特定的网络地址

### 绑定流程

1. 填充sockaddr_in结构

    ```cpp
    sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(4567);
    sin.sin_addr.S_un.S_addr = INADDR_ANY;

    ```
2. bind
    
    ```cpp
    bind(sListen, (LPSOCKADDR)&sin, sizeof(sin);
    ```

## 设置套接字进入监听模式

```cpp
    int listen（
		SOCKET s,     /*已绑定的套接字*/
		int backlog  /*等待连接队列长度*/
		)；
    /*
    返回值：
    成功：返回0
    失败：返回SOCKET_ERROR
    */
```

函数功能
1. 适用于支持连接的套接字
2. Internet通信域，仅仅适用于字节流套接字（TCP），且**仅用于服务器端**
3. 监听套接字必须已绑定在特定的网络地址上。
4. 监听套接字能监听来自客户端的连接请求，并规定了等待连接队列（先进先出队列）的最大长度。
5. 如果一个连接请求到达，并且排队已满，客户端将接收到WSAECONNREFUSED错误


## 接受连接请求

```cpp
    SOCKET accept(
        SOCKET s,                   /*服务端处的监听套接字*/
        struct sockaddr* addr,  /*出口参数，客户端地址结构*/
        int* addrlen                   /*出口参数，客户端地址长度*/
    );
    /*
    返回值：
    成功：新的套接字描述符。
    失败：INVALID_SOCKET错误。
    */
```

功能
1. 从监听套接字的等待队列中抽取连接请求，创建一个新的套接字来与请求连接的客户端套接字创建连接通道，交换数据
2. 若队列中没有连接请求
   1. 阻塞方式时，该函数阻塞调用它的进程
   2. 非阻塞方式时，返回一个错误代码

## 发起连接请求

```cpp
    int connect (
        SOCKET s,                           // 若没有绑定，系统自动绑定
        const struct sockaddr *  name,      // 服务器地址结构
        int namelen                         // 地址结构长度，由于name给的指针
    );
    // 成功：返回0 失败：返回SOCKET_ERROR

```

## 字节流套接字收发数据

send 
```cpp
    int send (
        SOCKET s,           // 已建立连接的套接字
        const char  * buf,  // 发送缓冲区（注意const）
        int len,            // 待发送长度
        int flags           // 选项
    );
    // 成功：返回实际发送的字节数 失败：返回SOCKET_ERROR
```

数据报类型的套接字，发送数据的长度**不应超过**子网的IP包最大长度。

最大长度由WSADATA结构中定义

完成send调用不意味着数据能传送到对方。

recv
```cpp
    int recv (
        SOCKET s,   // 同上
        char * buf, // 接受缓冲区
        int len,    // 缓冲区长度
        int flags   // 选项
    );

    // 成功：返回实际接收的字节数；连接已终止：0；失败：返回SOCKET_ERROR

```

## 数据报套接字收发数据

```cpp
    int sendto (
        SOCKET s,
        const char  * buf,
        int len,
        int flags，
        const struct sockaddr  * to，   // 同connect的参数
        int  tolen                      // 同connect
    );
    // 可以肤浅地理解成connect+send
```

```cpp
    int recvfrom (
        SOCKET s,
        char  * buf,
        int len,
        int flags，
        struct sockaddr  * from，
        int * fromlen
    );
```

数据报**也可以**像字节流那样connect + send

## 错误信息获取

WSAGetLastError

```cpp
   int  WSAGetLastError (void);
   // 返回详细的错误代码
```

WSAStartup调用失败不能用这个获得错误代码，因为还未建立储存错误信息的空间。

# socket到底是啥？

仅仅时一个32位标识符

1. 该套接字所关联的本地和远程互联网地址和端口号。
2. 一个FIFO（First Im First Out）队列，用于存放接收到的等待分配的数据，以及一个用于存放等待传输的数据的队列。
3. 对于TCP套接字，还包含了与打开和关闭TCP握手相关的额定协议状态信息。
