#include "Clinet.h"
#include "Server.h"
Client::Client():NetworkStream()
{
	connection = new TcpConnection();
	connection->stream = this;
}

Client::~Client()
{
	connection->stream = nullptr;
	delete connection;
	connection = nullptr;
}

void Client::OnConnected()
{
}

void Client::OnDisconnected()
{
	gServer.client_pool.Free(uid);
}
