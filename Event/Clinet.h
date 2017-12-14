#pragma once
#include "NetwrokStream.h"
#include "TcpConnection.h"
class Client:public NetworkStream
{
public:
	Client();
	~Client();

public:
	uint uid;
public:
	virtual void OnConnected();
	virtual void OnDisconnected();

};

