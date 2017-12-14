#include "TcpConnection.h"
#include "NetwrokStream.h";

TcpConnection::TcpConnection()
{
}

TcpConnection::~TcpConnection()
{
}

void TcpConnection::OnConnected()
{
}

void TcpConnection::SetSocket(int socket, sockaddr* addr, struct event_base *base)
{
	m_BufferEvent = bufferevent_socket_new(base, socket, BEV_OPT_CLOSE_ON_FREE);
	bufferevent_setcb(m_BufferEvent, ReadEvent, WriteEvent, SocketEvent, this);
	bufferevent_enable(m_BufferEvent, EV_READ | EV_PERSIST);
	if (stream)stream->OnConnected();
}

int TcpConnection::Send(char * buff, int len)
{
	return bufferevent_write(m_BufferEvent, buff, len);
}

void TcpConnection::OnRevcMessage()
{
	if (stream)
	{
		int empty = stream->read_buff_end - stream->read_offset;
		int len = bufferevent_read(m_BufferEvent, stream->read_offset, empty);
		stream->read_offset += len;
		stream->OnParseMessage();
	}
}

void TcpConnection::ReadEvent(bufferevent * bev, void * arg)
{
	TcpConnection* con = (TcpConnection*)arg;
	con->OnRevcMessage();
	/*char msg[4096];
	size_t len = bufferevent_read(bev, msg, sizeof(msg) - 1);

	msg[len] = '\0';
	printf("Server read the data: %s\n", msg);

	char reply[] = "I have read your data.";

	bufferevent_write(bev, reply, strlen(reply));*/
}

void TcpConnection::WriteEvent(bufferevent * bev, void * arg)
{
}

void TcpConnection::SocketEvent(bufferevent * bev, short events, void * arg)
{
	if (events & BEV_EVENT_EOF) {
		printf("connection closed\n");
	}
	else if (events & BEV_EVENT_ERROR) {
		printf("some other error\n");
	}
	TcpConnection* c = (TcpConnection*)arg;
	evutil_closesocket(c->m_Socket);
	bufferevent_free(bev);
	if (c->stream)c->stream->OnDisconnected();
}
