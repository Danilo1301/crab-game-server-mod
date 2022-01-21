#include "SocketServer.h"

bool SocketServer::m_IsConnected = false;
sio::client SocketServer::m_Client;
long long SocketServer::m_LastSentLobbyId = 0;