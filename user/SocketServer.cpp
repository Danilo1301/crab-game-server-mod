#include "pch-il2cpp.h"
#include "SocketServer.h"

bool SocketServer::m_IsConnected = false;
bool SocketServer::m_FirstConnect = true;
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
	m_IsConnected = true;

	if (!m_FirstConnect) {
		std::cout << "[SocketServer] Reconnected to server!" << std::endl;
		return;
	}

	m_FirstConnect = false;

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
	//std::cout << ("Close") << std::endl;
}

void SocketServer::on_fail()
{
	//std::cout << ("Fail") << std::endl;
}

void SocketServer::Connect()
{
	m_Client.set_logs_quiet();
	m_Client.set_open_listener(&on_connected);
	m_Client.set_close_listener(&on_close);
	m_Client.set_fail_listener(&on_fail);

	//std::cout << "[SocketServer] Connecting..." << std::endl;

	m_Client.connect("http://crabgame-server.herokuapp.com");
	//m_Client.connect("http://127.0.0.1:3000");

	while (true)
	{
		Sleep(1000);
	}
}