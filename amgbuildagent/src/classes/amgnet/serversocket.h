#ifndef __SERVERSOCKET_H_INCLUDED__
#define __SERVERSOCKET_H_INCLUDED__

#include <iostream>
#define _WINSOCKAPI_
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _XOPEN_SOURCE
#include <memory>
#include <string>
#include <ctime>
#include <vector>
#include <sys/types.h>
#if !defined(WIN32) && !defined(_WIN32) && !defined(__WIN32) && !defined(__CYGWIN__)
    #include <unistd.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <netdb.h>
    #include <arpa/inet.h>
    #include <sys/wait.h>
#else
    #include <ws2tcpip.h>
    #pragma comment(lib, "Ws2_32.lib")
    #define __ISWINDOWS__
#endif
#include <signal.h>
using namespace std;

namespace amgnet {
    template <class T>
    class ServerSocket {
        protected:
            int serverPort;
            string serverName;
			struct addrinfo serverAddrInfo, *serverAddrInfoPtr;
            T listeningFD;
            const int bufferSize = 9999;
            char buffer[9999];
            vector<T> clientFD;
            virtual void initializeWinsock();
            virtual void createSocket();
            virtual void bindSocket();
            virtual void markReady();
            virtual void cleanupWinsock();
            virtual string read(T client, char *buffer);
            virtual void write(T client, string message);
            virtual void closeClientSockets();
        public:
            ServerSocket(int p = 0, string name = "");
            virtual ~ServerSocket();
            virtual T getListeningFD();
            virtual vector<T> getClientFD();
            virtual int getServerPort();
            virtual string getServerName();
            virtual void startServer();
    };
}
#endif
