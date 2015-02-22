#include "Print.h"
#include "Web.h"

#include <Arduino.h>

#define SD_CARD_PIN 4

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

Web web(mac, 80);

void servoHandler(WebServer& server, WebServer::ConnectionType type, char *tail,
    bool tailComplete) {
}

void setup() {
  Serial.begin(9600);

  // Disable DS card
  pinMode(SD_CARD_PIN, OUTPUT);
  digitalWrite(SD_CARD_PIN, HIGH);

  web.addHandler("servo", &servoHandler);
}

void loop() {
  web.accept();
}

