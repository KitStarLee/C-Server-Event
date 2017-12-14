#pragma once
#include <event2/event.h>
#include <event2/event_struct.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/listener.h>
#include <string>
using namespace std;
class TcpListener
{
public:
	int m_Socket;
	//struct event m_ListenEvent;
	struct event m_AcceptEvent;
	struct event_base* m_BaseEvent;
	struct sockaddr_in m_ListenAddr;
	evconnlistener *m_Listener;
public:
	void CreateServer(const char *ip, int port,int max_client);
	static void ListenEvent(evconnlistener *listener, evutil_socket_t fd,sockaddr *sock, int socklen, void *arg);
	virtual void OnAccept(int socket, sockaddr*);
};