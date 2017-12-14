#pragma once
#ifndef __NETWORK_STREAM_H__
#define __NETWORK_STREAM_H__
#include "common.h"
typedef enum
{
	READERROR=0,WRITEERROR=1
}NETERR;
class TcpConnection;
class NetworkStream
{

public:
	NetworkStream(int send_buff_size = 1024*512,int read_buff_size = 1024 * 512);
	~NetworkStream();
public:
	char* write_buff;
	char* write_position;
	char* write_end;
	char* write_buff_end;

	char* read_offset;
	char* read_buff;
	char* read_end;
	char* read_position;
	char* read_buff_end;
	TcpConnection* connection;
public:
//////////////////////////////////////////////////////////////
//write data
public:
	void WirteByte(byte data);
	void WirteByte(char data);
	void WriteShort(short data);
	void WriteUShort(ushort data);
	void WriteInt(int data);
	void WriteUInt(uint data);
	void WriteFloat(float data);
	void WriteLong(long data);
	void WriteULong(ulong data);
	void WriteString(const char* str);
	void WriteData(const void* data, int count);
	void BeginWrite();
	void EndWrite();
	//////////////////////////////////////////////////////////////
	//read data
public:
	void ReadByte(byte &data);
	void ReadByte(char &data);
	void ReadShort(short &data);
	void ReadUShort(ushort &data);
	void ReadInt(int &data);
	void ReadUInt(uint &data);
	void ReadFloat(float &data);
	void ReadLong(long &data);
	void ReadULong(ulong &data);
	int ReadString(char* str,int size);
	void ReadData(void* data, int count);
public:
	virtual void OnParseMessage();
	virtual void OnMessage();
	virtual void OnConnected();
	virtual void OnDisconnected();

};
#endif