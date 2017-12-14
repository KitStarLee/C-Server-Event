#include <sys/types.h>  


#include <event2/event-config.h>  

#ifdef _WIN32
#define WIN32
#endif // _WIN32

#include <sys/stat.h>  
#ifndef WIN32  
#include <sys/queue.h>  
#include <unistd.h>  
#endif  
#include <time.h>  
#ifdef _EVENT_HAVE_SYS_TIME_H  
#include <sys/time.h>  
#endif  
#include <fcntl.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>  
#include <errno.h>  


#include <event2/event.h>  
#include <event2/event_struct.h>  
#include <event2/util.h>  


#ifdef WIN32  
#include <winsock2.h>  
#endif  

#pragma comment(lib,"libevent\\build_lib\\windows\\libevent.lib")
#pragma comment(lib,"libevent\\build_lib\\windows\\libevent_core.lib")
#pragma comment(lib,"libevent\\build_lib\\windows\\libevent_extras.lib")


struct timeval lasttime;


int event_is_persistent;


static void timeout_cb(evutil_socket_t fd, short event, void *arg)
{
	struct timeval newtime, difference;
	struct event *timeout = (struct event*)arg;
	double elapsed;


	evutil_gettimeofday(&newtime, NULL);
	evutil_timersub(&newtime, &lasttime, &difference);
	elapsed = difference.tv_sec +
		(difference.tv_usec / 1.0e6);


	printf("timeout_cb called at %d: %.3f seconds elapsed.\n",
		(int)newtime.tv_sec, elapsed);
	lasttime = newtime;


	if (!event_is_persistent) {
		struct timeval tv;
		evutil_timerclear(&tv);
		tv.tv_sec = 2;
		event_add(timeout, &tv);
	}
}

#include "Server.h"
int main(int argc, char **argv)
{
	gServer.Init();
	gServer.CreateServer("127.0.0.1", 8080,MAX_CLIENT);
	return 0;
}