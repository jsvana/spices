#include "Web.h"

Web::Web(byte mac[], int port) {
  server = new WebServer("", port);

  if (!Ethernet.begin(mac)) {
    Serial << "Error getting DHCP lease\n";
    for (;;) {}
  }

  Serial << "Server IP: " << Ethernet.localIP() << "\n";

  server->begin();
}

void Web::addDefaultHandler(handlerFunc handler) {
  server->setDefaultCommand(handler);
}

void Web::addHandler(const char *path, handlerFunc handler) {
  server->addCommand(path, handler);
}

void Web::accept() {
  server->processConnection();
}
