<a id="library"></a>

# gbj\_appota
This is an application library, which is used usually as a project library for particular PlatformIO project. However; in every project utilizing the OTA (Over the air) functionality should be copied the same library, so that it is located in central library storage.

- Library specifies (inherits from) the application `gbj_appcore` library.
- Library utilizes error handling from the parent class.
- Library creates internal HTTP server for OTA.


<a id="dependency"></a>

## Dependency

- **gbj\_appcore**: Parent library loaded from the file `gbj_appcore.h`.
- **gbj\_serial\_debug**: Auxilliary library for debug serial output loaded from the file `gbj_serial_debug.h`. It enables to exclude serial outputs from final compilation.
- **ESPAsyncWebServer**: External library for creating HTTP servers loaded from the file `ESPAsyncWebServer.h`.
- **AsyncElegantOTA.h**: External library for OTA updates of firmware over HTTP server loaded from the file `AsyncElegantOTA.h`.

#### Espressif ESP8266 platform
- **Arduino.h**: Main include file for the Arduino platform.
- **ESP8266WiFi.h**: Main include file for the wifi connection.
- **ESPAsyncTCP.h**: Main include file for asynchronuous connection with HTTP servers.

#### Espressif ESP32 platform
- **Arduino.h**: Main include file for the Arduino platform.
- **WiFi.h**: Main include file for the wifi connection.
- **AsyncTCP.h**: Main include file for asynchronuous connection with HTTP servers.

> Library is not intended to be utilized on Arduino or Particle platform.


<a id="constants"></a>

## Constants

- **gbj\_appota::VERSION**: Name and semantic version of the library.

Other constants and enumerations are inherited from the parent library.


<a id="interface"></a>

## Interface

- [gbj_appota()](#gbj_appota)
- [begin()](#begin)


<a id="gbj_appota"></a>
## gbj_appota()

#### Description
Constructor creates the class instance object and initiates internal resources.

#### Syntax
    gbj_appota(unsigned int port)

#### Parameters
- **port**: Listening TCP port for HTTP server.
  - *Valid values*: non-negative integer
  - *Default value*: 80

#### Returns
Object enabling OTA functionality.

[Back to interface](#interface)


<a id="begin"></a>

## begin()

#### Description
The method initiates OTA functionality and starts the HTTP server.
- HTTP server should be accessed in an internet browser on IP address and eventually defined port of the wifi connection of the device.
- The server respondes with a simple one-line message containinginfo about accessing OTA functionality.
- The OTA functionality is accessable on HTTP server subpage with suffix `/update`.

#### Syntax
	void begin()

#### Parameters
None

#### Returns
None

#### Example
```cpp
gbj_appota ota = gbj_appota();
// gbj_appota ota = gbj_appota(8080);
void setup()
{
  ota.begin();
}
```

[Back to interface](#interface)
