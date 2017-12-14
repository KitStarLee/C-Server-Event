#pragma once

#include <event2/event.h>
#include <event2/event_struct.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include<WinSock2.h>
class NetworkStream;
class TcpConnection
{
public:
	TcpConnection();
	~TcpConnection();

public:
	int m_Socket;
	bufferevent *m_BufferEvent;
	NetworkStream* stream;
public:
	virtual void OnConnected();
	void SetSocket(int socket, sockaddr* addr,struct event_base *base);
	int Send(char* buff, int len);
	void OnRevcMessage();
	static void ReadEvent(bufferevent *bev, void *arg);
	static void WriteEvent(bufferevent *bev, void *arg);
	static void SocketEvent(bufferevent *bev, short events, void *arg);

};


