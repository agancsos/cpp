#include "serversocket.h"

namespace amgnet {
    template <class T>
    ServerSocket<T>::ServerSocket(int p, string name) {
        this->serverPort = p;
        this->serverName = name;
    }

    template <class T>
    ServerSocket<T>::~ServerSocket() { }

    template <class T>
    void ServerSocket<T>::startServer() {
        this->initializeWinsock();
        this->createSocket();
        this->bindSocket();
        this->markReady();
        while(true) {
            string commandBuffer = "";
            memset(this->buffer, 0, 9999);
            sockaddr_in clientHint;
            int clientSize = sizeof(clientHint);
            T newClient; 
			#if defined(__ISWINDOWS__)
				newClient = accept(this->listeningFD, (sockaddr*)&clientHint, &clientSize);
			#else
				socklen_t size2 = sizeof(clientHint);
				newClient = accept(this->listeningFD, (struct sockaddr *) &clientHint, &size2);
			#endif
            this->clientFD.push_back(newClient);
            while(true) {
                int num = recv(newClient,buffer,bufferSize,0);
                if (num < 1) break;
                commandBuffer += string(buffer);
                memset(buffer, 0, this->bufferSize);
                cout << string(commandBuffer) << endl;
                send(newClient, buffer, commandBuffer.length(), 0);
                strcpy(buffer, "");
                if(commandBuffer[num] == '\n') {
                    cout << commandBuffer << endl;
                    commandBuffer = "";
                }
            }
        }
        this->closeClientSockets();
        this->cleanupWinsock();
    }

    template <class T>
    void ServerSocket<T>::write(T client, string message) {
        send(client, message.c_str(), message.length(), 0);
        send(client, "\n", 1, 0);
    }

    template <class T>
    string ServerSocket<T>::read(T client, char *buffer) {
        string commandBuffer = "";
        while(true) {
            int num = recv(client,buffer,bufferSize,0);
            if (num < 1) break;
            commandBuffer += string(buffer);
            memset(buffer, 0, this->bufferSize);
            cout << string(commandBuffer) << endl;
            send(client, buffer, commandBuffer.length(), 0);
            strcpy(buffer, "");
            if(commandBuffer[num] == '\n') {
                cout << commandBuffer << endl;
                commandBuffer = "";
            }
        }
        return commandBuffer;
    }

    template <class T>
    void ServerSocket<T>::initializeWinsock() {
        #ifdef __ISWINDOWS__
            WSAData data;
            int startupOkay = WSAStartup(MAKEWORD(2,2), &data);
            if(startupOkay != 0) { return; }
        #endif
    }

    template <class T>
    void ServerSocket<T>::createSocket() {
		memset(&this->serverAddrInfo, 0, sizeof(this->serverAddrInfo));
		this->serverAddrInfo.ai_family = AF_INET;  
		this->serverAddrInfo.ai_socktype = SOCK_STREAM;
		this->serverAddrInfo.ai_flags = AI_PASSIVE;
		if (getaddrinfo(NULL, to_string(this->serverPort).c_str(), &this->serverAddrInfo, &this->serverAddrInfoPtr) != 0) {
			throw "Failed to get address...";
		}
		#if defined( __ISWINDOWS__)
			this->listeningFD = socket(this->serverAddrInfoPtr->ai_family, this->serverAddrInfoPtr->ai_socktype, this->serverAddrInfoPtr->ai_protocol);
        #else
			this->listeningFD = socket(this->serverAddrInfoPtr->ai_family, this->serverAddrInfoPtr->ai_socktype, this->serverAddrInfoPtr->ai_protocol);
            if (this->listeningFD < 0)
                cout << "Failed to create socket..." << endl;
        #endif
    }

    template <class T>
    void ServerSocket<T>::bindSocket() {
		#if defined( __ISWINDOWS__)
        	::bind(this->listeningFD, this->serverAddrInfoPtr->ai_addr, this->serverAddrInfoPtr->ai_addrlen);
		#else
			::bind(this->listeningFD, this->serverAddrInfoPtr->ai_addr, this->serverAddrInfoPtr->ai_addrlen);
		#endif
    }

    template <class T>
    void ServerSocket<T>::markReady() {
		int status = listen(this->listeningFD, 50);
		if (status < 0)
			cout << "Error marking socket ready..." << endl;
		else
			cout << "Listening on port: " << this->serverPort << endl;
    }

    template <class T>
    void ServerSocket<T>::cleanupWinsock() {
        #ifdef __ISWINDOWS__
            WSACleanup();
        #endif
    }

    template <class T>
    void ServerSocket<T>::closeClientSockets() {
        for(T client : this->clientFD) {
			#if defined __ISWINDOWS__
            	closesocket(client);
			#else
				close(client);
			#endif
        }
    }

    template <class T> 
	T ServerSocket<T>::getListeningFD() { return this->listeningFD; }
    
	template <class T> 
	vector<T> ServerSocket<T>::getClientFD() { return this->clientFD; }
    
	template <class T> 
	int ServerSocket<T>::getServerPort() { return this->serverPort; }
    
	template <class T> 
	string ServerSocket<T>::getServerName() { return this->serverName; }
}
