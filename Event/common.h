#pragma once
#ifndef __COMMON_H__
#define __COMMON_H__
typedef unsigned char byte;
typedef byte uint8;
typedef long int64;
typedef unsigned long uint64;

typedef unsigned int uint32;
typedef int int32;
typedef unsigned short uint16;
typedef short int16;
#ifdef _WIN32
//#include <windows.h>
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
#endif // MSBUILD

//#ifdef _WIN32
//#include <WinSock.h>
//#pragma comment(lib,"wsock32")
//#else
//#include <unistd.h>
//#include <stdio.h>
//#include <sys/socket.h>
//#include <fcntl.h>
//#include <errno.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//#include <sys/types.h>
//#endif
#endif
