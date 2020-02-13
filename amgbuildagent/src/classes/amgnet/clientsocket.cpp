#include "clientsocket.h"

namespace amgnet {
    template <class T>
    ClientSocket<T>::ClientSocket() {

    }

    template <class T>
    ClientSocket<T>::~ClientSocket() { }

    template <class T>
    bool ClientSocket<T>::connect2(string host, int port) {
        this->initializeWinsock();
        if(this->clientFD == -1){ 
            this->createSocket();
        }
        sockaddr_in serverHint;
        serverHint.sin_addr.s_addr = inet_addr(host.c_str());        
        serverHint.sin_family = AF_INET;
        serverHint.sin_port = htons(port);
        
        if (connect(this->clientFD , (struct sockaddr *)&serverHint , sizeof(serverHint)) < 0) {
            return false;
        }
        return true;
    }

    template <class T>
    void ClientSocket<T>::write(T client, string message) {
        send(client, message.c_str(), message.size() + 1, 0);
    }

    template <class T>
    int ClientSocket<T>::read(T client, char *buffer) {
        int bytes = recv(client, buffer, this->bufferSize, 0);
        return bytes;
    }

    template <class T>
    void ClientSocket<T>::initializeWinsock() {
        #ifdef __ISWINDOWS__
            WSAData data;
            int startupOkay = WSAStartup(MAKEWORD(2,2), &data);
            if(startupOkay != 0) { return; }
        #endif
    }

    template <class T>
    void ClientSocket<T>::createSocket() {
        #ifdef __ISWINDOWS__
            this->clientFD = socket(AF_INET, SOCK_STREAM, 0);
        #else
            this->clientFD = socket(AF_INET, SOCK_STREAM, 0);
        #endif
    }

    template <class T>
    void ClientSocket<T>::cleanupWinsock() {
        #ifdef __ISWINDOWS__
            WSACleanup();
        #endif
    }
}