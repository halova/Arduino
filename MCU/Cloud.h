
//#include <ArduinoIoTCloud.h>
//#include <Arduino_ConnectionHandler.h>

char ssid[] = SECRET_SSID;                // network SSID (name)
char pass[] = SECRET_PASS;                // network password (use for WPA, or use as key for WEP)
int status = WL_IDLE_STATUS;             // the Wi-Fi radio's status

byte mac[6];
// Gobal value for reading vol //
float vol;

void initProperties(){

  ArduinoCloud.addProperty(vol, READ, 1 * SECONDS, NULL);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(ssid, pass);

void Wifi_Init()
{
  // attempt to connect to Wi-Fi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to network: ");
    Serial.println(ssid);
    
    // Connect to WPA/WPA2 network:
    status = WiFi.begin(ssid, pass);
    //status = WiFi.begin(ssid);
    // wait 1.5 seconds for connection:
    delay(1500);
  }
  ///////////////////
   Serial.println("Attempting to connect to the Cloud");
     // Call function to set up Cloud connection //
  initProperties();
  // Connect to Arduino IoT Cloud
  // Pass ssid and pass to the cloud setting.
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  delay(1500);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  //ArduinoCloud.connected();
  // wait 1.5 seconds for connection:
  ///////////////
    //connected now, so print out the data:
    Serial.println("You're connected to the network");
    Serial.println("---------------------------------------");
    Serial.println("Board Information:");
    // print board's IP address:
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);

    // print network's SSID:
    Serial.println("Network Information:");
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());

    // print the received signal strength //
    long rssi = WiFi.RSSI();
    Serial.print("signal strength (RSSI):");
    Serial.println(rssi);
    Serial.println("---------------------------------------");
    /*
    // Why this has to be this long ??//
    WiFi.macAddress(mac);
    Serial.print("MAC: ");
    Serial.print(mac[5],HEX);
    Serial.print(":");
    Serial.print(mac[4],HEX);
    Serial.print(":");
    Serial.print(mac[3],HEX);
    Serial.print(":");
    Serial.print(mac[2],HEX);
    Serial.print(":");
    Serial.print(mac[1],HEX);
    Serial.print(":");
    Serial.println(mac[0],HEX);
    Serial.println("---------------------------------------");
    */
    
}