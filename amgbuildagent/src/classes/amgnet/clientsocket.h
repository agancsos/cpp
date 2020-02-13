#ifndef __CLIENTSOCKET_H_INCLUDED__
#define __CLIENTSOCKET_H_INCLUDED__

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
    class ClientSocket {
        protected:
            sockaddr_in clientHint;
            T clientFD;
            const int bufferSize = 9999;
            char buffer[9999];
            virtual void initializeWinsock();
            virtual void cleanupWinsock();
            virtual void createSocket();
            virtual int read(T client, char *buffer);
            virtual void write(T client, string message);
        public:
            ClientSocket();
            virtual ~ClientSocket();
            virtual bool connect2(string host, int port);
    };
}
#endif