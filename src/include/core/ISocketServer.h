#pragma once

#include <thread>
#include <exception>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>

#include "core/ISocketClient.h"
#include "util/logger.h"

namespace Robust
{
// A simple server that forwards tcp requests
class ISocketServer
{
protected:
  std::thread ListenerThread; // Asynchronous listening for handshakes
  void Listener();            // Listens for handshakes

  virtual void HandleRequest(int) {} // Once a request is fufilled, this function decides what is done with the client socket

  int MakeSocket(); // Registers server socket and binds it to port

  int WaitForClient(); // Halts thread until there is a request

  const int Port; // Port that the server is listening on

  int ServerSock;

public:
  void Join();
  void Detach();
  ISocketServer(int); // Constructs server with specified port
  ~ISocketServer();
};
} // namespace Robust
