#include "pch-il2cpp.h"
#include "SocketServer.h"

#include <iostream>       
#include <sstream>        
#include <ctime>          
#include <locale> 

bool SocketServer::m_Connected = false;
bool SocketServer::m_Connecting = false;

sio::client SocketServer::m_Client;
Json::Value SocketServer::m_LastPacket = Json::nullValue;

void SocketServer::Emit(std::string id, Json::Value data)
{
	std::cout << "[SocketServer] Sending packet '" << id << "'" << std::endl;

	Json::Value value = Json::objectValue;
	value["id"] = id;
	value["data"] = data;

	m_Client.socket()->emit("packet", value.toStyledString());
}

void SocketServer::on_connected()
{
	m_Connecting = false;
	m_Connected = true;

	std::cout << "[SocketServer] Connected to server!" << std::endl;

	m_Client.socket()->on("packet", sio::socket::event_listener_aux([&](std::string name, sio::message::ptr const& data, bool isAck, sio::message::list& ack_resp)
		{
			auto packetStr = data->get_string();

			Json::Value packet;
			Json::Reader reader;
			bool parsingSuccessful = reader.parse(packetStr.c_str(), packet);
			if (!parsingSuccessful)
			{
				std::cout << "[SocketServer] Failed to parse packet received, " << reader.getFormattedErrorMessages();
				return;
			}

			std::cout << "[SocketServer] Received packet '" << packet["id"].asString() << "' " << packet["data"] << std::endl;

			m_LastPacket = packet;
		}));
}

void SocketServer::on_close(sio::client::close_reason const& reason)
{
	m_Connecting = false;
	m_Connected = false;
	std::cout << "[SocketServer] Closed" << std::endl;
}

void SocketServer::on_fail()
{
	m_Connecting = false;

	std::cout << "[SocketServer] Fail" << std::endl;
}

void SocketServer::Connect()
{
	bool connectLocalHost = false;
	bool useTwoServers = true;
	int connectToServer = 1;

	m_Client.set_logs_quiet();
	m_Client.set_open_listener(&on_connected);
	m_Client.set_close_listener(&on_close);
	m_Client.set_fail_listener(&on_fail);

	if (connectLocalHost) {
		m_Client.connect("http://127.0.0.1:3000");
	}
	else {
		if (useTwoServers) {
			auto now = std::chrono::system_clock::now();
			time_t t = std::chrono::system_clock::to_time_t(now);
			tm timePtr;
			localtime_s(&timePtr, &t);

			auto day = timePtr.tm_mday;

			if (day > 15) connectToServer = 1;
		}

		if (connectToServer == 1) {
			m_Client.connect("http://crabgame-server.herokuapp.com");
		}
		else {
			m_Client.connect("http://crabgame-server-2.herokuapp.com");
		}
	}

	m_Connecting = true;

	/*
	while (m_Connected || m_Connecting)
	{
		Sleep(1000);
	}
	*/
}

void SocketServer::Close()
{
	m_Connecting = false;
	m_Connected = false;

	m_Client.close();
}