#pragma once

#include "pch.h"

class SocketServer {
private:
	
public:
	static bool m_IsConnected;
	static sio::client m_Client;
	static long long m_LastSentLobbyId;

	static void SendLobbyInfo(long long lobbyId) {
		if (m_LastSentLobbyId == lobbyId) return;
		m_LastSentLobbyId = lobbyId;

		Emit("new lobby created: " + lobbyId);

		//MessageBoxA(NULL, "Sending lobby info", NULL, NULL);
	}

	static void Emit(std::string message) {
		//MessageBoxA(NULL, "emit", NULL, NULL);

		m_Client.socket()->emit("logmessage", message);
	}

	static void on_connected()
	{
		//MessageBoxA(NULL, "Connected", NULL, NULL);

		std::cout << ("Connect") << std::endl;

		m_IsConnected = true;
	}

	static void on_close(sio::client::close_reason const& reason)
	{
		std::cout << ("Close") << std::endl;
	}

	static void on_fail()
	{
		std::cout << ("Fail") << std::endl;

	}

	static void Connect() {
		
		m_Client.set_open_listener(&on_connected);
		m_Client.set_close_listener(&on_close);
		m_Client.set_fail_listener(&on_fail);

		//MessageBoxA(NULL, "Connecting...", NULL, NULL);


#if SIO_TLS
		std::cout << ("Connecting TLS...") << std::endl;
#else
		std::cout << ("Connecting...") << std::endl;

#endif
		m_Client.connect("http://crabgame-server.herokuapp.com");
		//m_Client.connect("http://127.0.0.1:3000");

		while (true)
		{
			//sio::message::list li("sports");
			//li.push(sio::string_message::create("economics"));
			//m_Client.socket()->emit("logmessage", li);

			//m_Client.socket()->emit("logmessage", std::string("emited"));
			Sleep(1000);
		}
	}
};