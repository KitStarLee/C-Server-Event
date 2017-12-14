#include "Server.h"
Server gServer;
Server::Server()
{
}

Server::~Server()
{
}

void Server::OnAccept(int socket, sockaddr * addr)
{
	Client* c = client_pool.Allocate();
	printf("clinet connected uid %d", c->uid);
	online_client.push_back(c);
	c->connection->SetSocket(socket, addr, m_BaseEvent);

}

void Server::Init()
{
	client_pool.Initialize(MAX_CLIENT);
}
