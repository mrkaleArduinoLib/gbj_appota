/*
  NAME:
  gbj_appota

  DESCRIPTION:
  Application library for creating HTTP server on the device for OTA firmware
  update with the library AsyncElegantOTA.

  LICENSE:
  This program is free software; you can redistribute it and/or modify
  it under the terms of the license GNU GPL v3
  http://www.gnu.org/licenses/gpl-3.0.html (related to original code) and MIT
  License (MIT) for added code.

  CREDENTIALS:
  Author: Libor Gabaj
 */
#ifndef GBJ_APPOTA_H
#define GBJ_APPOTA_H

#if defined(ESP8266)
  #include <ESP8266WiFi.h>
  #include <ESPAsyncTCP.h>
#elif defined(ESP32)
  #include <AsyncTCP.h>
  #include <WiFi.h>
#else
  #error !!! Only Espressif platforms are supported !!!
#endif
#include "gbj_appcore.h"
#include "gbj_serial_debug.h"
#include <Arduino.h>
#include <AsyncElegantOTA.h>
#include <ESPAsyncWebServer.h>

#undef SERIAL_PREFIX
#define SERIAL_PREFIX "gbj_appota"

class gbj_appota : public gbj_appcore
{

public:
  /*
    Constructor.

    DESCRIPTION:
    Constructor creates the class instance object and HTTP server instance.

    PARAMETERS:
    port - Listening port for HTTP server.
      - Data type: non-negative integer
      - Default value: 80
      - Limited range: 65535

    RETURN: object
  */
  inline gbj_appota(unsigned int port = 80)
  {
    server_ = new AsyncWebServer(port);
  }

  /*
    Initialize web server.

    DESCRIPTION:
    The method should be called in the SETUP section of a sketch.

    PARAMETERS: none

    RETURN: Result code.
  */
  inline void begin(String deviceName = "Device")
  {
    SERIAL_ACTION("Begin HTTP server...");
    server_->on("/",
                HTTP_GET,
                [deviceName](AsyncWebServerRequest *request)
                {
                  request->send(200,
                                "text/plain",
                                deviceName +
                                  " is ready for OTA. Go to '<IP>/update'.");
                });
    AsyncElegantOTA.begin(server_);
    server_->begin();
    SERIAL_ACTION_END("OK");
  }

private:
  AsyncWebServer *server_;
};

#endif
