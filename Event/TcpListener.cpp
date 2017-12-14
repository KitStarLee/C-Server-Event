#include "TcpListener.h"

void TcpListener::CreateServer(const char *ip, int port, int max_client)
{
#ifdef WIN32  
	WSAData wsaData;
	WSAStartup(MAKEWORD(2, 0), &wsaData);
#endif  
	memset(&m_ListenAddr, 0, sizeof(m_ListenAddr));
	m_ListenAddr.sin_family = AF_INET;
	m_ListenAddr.sin_addr.s_addr = inet_addr(ip);
	m_ListenAddr.sin_port = htons(port);

	m_BaseEvent = event_base_new();
	m_Listener = evconnlistener_new_bind(m_BaseEvent,
		ListenEvent, this,
		LEV_OPT_REUSEABLE | LEV_OPT_CLOSE_ON_FREE,
		max_client, (sockaddr*)&m_ListenAddr, sizeof(sockaddr_in));
	event_base_dispatch(m_BaseEvent);
	evconnlistener_free(m_Listener);
	event_base_free(m_BaseEvent);
}


void TcpListener::ListenEvent(evconnlistener * listener, evutil_socket_t fd, sockaddr * sock, int socklen, void * arg)
{
	printf("accept a client %d\n", fd);
	TcpListener *l = (TcpListener*)arg;
	l->OnAccept(fd, sock);

	/*bufferevent *bev = bufferevent_socket_new(l->m_BaseEvent, fd, BEV_OPT_CLOSE_ON_FREE);

	bufferevent_setcb(bev, socket_read_cb, NULL, socket_event_cb, NULL);
	bufferevent_enable(bev, EV_READ | EV_PERSIST);*/
}

void TcpListener::OnAccept(int socket, sockaddr* addr)
{
}
