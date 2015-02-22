#ifndef WEB_H_
#define WEB_H_

#include "Print.h"

#include <Arduino.h>
#include <SPI.h>
#include <EthernetV2_0.h>
#include <WebServer.h>

typedef void (*handlerFunc)(WebServer&, WebServer::ConnectionType, char *,
    bool);

class Web {
private:
  WebServer *server;

public:
  Web(byte mac[], int port);

  void addDefaultHandler(handlerFunc handler);
  void addHandler(const char *path, handlerFunc handler);

  void accept();
};

#endif
