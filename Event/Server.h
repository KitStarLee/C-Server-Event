#pragma once
#include "TcpListener.h"
#include "objectpool.h"
#include "Clinet.h"
#include<vector>
#define MAX_CLIENT 50
class Server:public TcpListener
{
public:
	Server();
	~Server();
public:
	ObjectPool<Client> client_pool;
	std::vector<Client*> online_client;

private:

	virtual void OnAccept(int socket, sockaddr* addr);
public:
	void Init();
	
};
extern Server gServer;
