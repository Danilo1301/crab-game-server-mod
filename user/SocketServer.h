#pragma once

#include "pch.h"
#include "Server.h"
#include "Mod.h"

class SocketServer {
private:
	
public:
	static bool m_IsConnected;
	static bool m_FirstConnect;
	static sio::client m_Client;
	static Json::Value m_LastPacket;

	static void Emit(std::string id, Json::Value data);

	static void on_connected();
	static void on_close(sio::client::close_reason const& reason);
	static void on_fail();

	static void Connect();
};