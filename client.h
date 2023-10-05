#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <thread>

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <Windows.h>
#pragma comment(lib, "ws2_32.lib")

#define CROSS_PLATFORM_SOCKET_ERROR SOCKET_ERROR

#define PORT 12345

SOCKET clientSocket;
struct sockaddr_in senderAddress;
struct sockaddr_in receiverAddress;
struct sockaddr_in serverAddress;

char buffer[1024];

std::string clientName;
std::string receiver;
std::string text;
std::string password;
char command;
bool toExit = false;


void menuPrompt();
bool createClientSocket();
struct sockaddr_in getAddress(std::string IP, int port);
bool sendMessage(std::string text, std::string name = "server");
void getMessage();
void registerClient();
std::string extractIPAddress(const std::string& input);
int extractPort(const std::string& input);
void handleMessage();
void closeConsole();
// check if the client is in the chat now or not and if it is even in the database at all
bool checkName(std::string name);
void sendMessage();
// get list of the clients in the chat
void getPresentClientsList();
void getMessageHistory();
void receiveMessages();
void console();


#endif // CLIENT_H


