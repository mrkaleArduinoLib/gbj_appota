<a id="library"></a>

# gbj\_appota
This is an application library, which is used usually as a project library for particular PlatformIO project. It encapsulates the functionality of the <abbr title='Over The Air'>OTA</abbr> firmware update. The encapsulation provides following advantages:

* Functionality is hidden from the main sketch.
* The library follows the principle `separation of concerns`.
* The library is reusable for various projects without need to code the OTA management.
* Update in library is valid for all involved projects.
* It specifies (inherits from) the parent application library `gbj_appcore`.
* It utilizes funcionality and error handling from the parent class.


## Fundamental functionality
* Library creates internal HTTP server for OTA.
* The HTTP functionality provides very simple informative and firmware upload page.


<a id="dependency"></a>

## Dependency
* **gbj\_appcore**: Parent library for all application libraries loaded from the file `gbj_appcore.h`.
* **gbj\_serial\_debug**: Auxilliary library for debug serial output loaded from the file `gbj_serial_debug.h`. It enables to exclude serial outputs from final compilation.
* **ESPAsyncWebServer**: External library for creating HTTP servers loaded from the file `ESPAsyncWebServer.h`.
* **AsyncElegantOTA**: External library for OTA updates of firmware over HTTP server loaded from the file `AsyncElegantOTA.h`.

#### Espressif ESP8266 platform
* **Arduino.h**: Main include file for the Arduino platform.
* **ESP8266WiFi.h**: Main include file for the wifi connection.
* **ESPAsyncTCP.h**: Main include file for asynchronuous connection with HTTP servers.

#### Espressif ESP32 platform
* **Arduino.h**: Main include file for the Arduino platform.
* **WiFi.h**: Main include file for the wifi connection.
* **AsyncTCP.h**: Main include file for asynchronuous connection with HTTP servers.

> Library is not intended to be utilized on Arduino or Particle platform.


<a id="interface"></a>

## Interface
* [gbj_appota()](#gbj_appota)
* [begin()](#begin)


<a id="gbj_appota"></a>

## gbj_appota()

#### Description
Constructor creates the class instance object and initiates internal resources.

#### Syntax
    gbj_appota(unsigned int port)

#### Parameters
* **port**: Listening TCP port for HTTP server.
  * *Valid values*: non-negative integer
  * *Default value*: 80

#### Returns
Object enabling OTA functionality.

[Back to interface](#interface)


<a id="begin"></a>

## begin()

#### Description
The method initiates OTA functionality and starts the HTTP server.
* HTTP server should be accessed in an internet browser on IP address and eventually defined port of the WiFi connection of the device.
* An optional input argument is used as a device name for better orientation. Usually it is a hostname of the microcontroller on wifi network.
* The server respondes with a simple one-line message page containing information about accessing OTA functionality.
* The OTA functionality is accessable on HTTP server subpage with suffix `/update`.

#### Syntax
	void begin(String deviceName)

#### Parameters
* **port**: Device name for information output.
  * *Valid values*: text of type String
  * *Default value*: "Device"

#### Returns
None

#### Example
```cpp
gbj_appota ota = gbj_appota();
// gbj_appota ota = gbj_appota(WIFI_PORT);
void setup()
{
  ota.begin();
  // ota.begin(WIFI_HOSTNAME);
}
```

[Back to interface](#interface)
