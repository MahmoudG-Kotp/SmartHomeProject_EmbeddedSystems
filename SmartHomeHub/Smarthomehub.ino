#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

/* Put your SSID & Password */
const char* ssid = "NodeMCU";  // Enter SSID here
const char* password = "12345678";  //Enter Password here

/* Put IP Address details */
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);

uint8_t LED1Enable = 1;
uint8_t LED1Disable = 2;
bool LED1status = LOW;

uint8_t LED2Enable = 3;
uint8_t LED2Disable = 4;
bool LED2status = LOW;

uint8_t LCDEnable = 5;
uint8_t LCDDisable = 6;
bool LCDstatus = LOW;


void setup() {
  Serial.begin(9600);
  
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);
  
  server.on("/", handle_OnConnect);
  server.on("/led1on", handle_led1on);
  server.on("/led1off", handle_led1off);
  server.on("/led2on", handle_led2on);
  server.on("/led2off", handle_led2off);
  server.on("/lcdon", handle_lcdon);
  server.on("/lcdoff", handle_lcdoff);
  server.onNotFound(handle_NotFound);
  
  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
  if(LED1status)
  {Serial.write(LED1Enable);}
  else
  {Serial.write(LED1Disable);}
  
  if(LED2status)
  {Serial.write(LED2Enable);}
  else
  {Serial.write(LED2Disable);}
  
  if(LCDstatus)
  {Serial.write(LCDEnable);}
  else
  {Serial.write(LCDDisable);}
}

void handle_OnConnect() {
  LED1status = LOW;
  LED2status = LOW;
  LCDstatus = LOW;
  server.send(200, "text/html", SendHTML(LED1status,LED2status,LCDstatus)); 
}

void handle_led1on() {
  LED1status = HIGH;
  server.send(200, "text/html", SendHTML(true,LED2status,LCDstatus)); 
}

void handle_led1off() {
  LED1status = LOW;
  server.send(200, "text/html", SendHTML(false,LED2status,LCDstatus)); 
}

void handle_led2on() {
  LED2status = HIGH;
  server.send(200, "text/html", SendHTML(LED1status,true,LCDstatus)); 
}

void handle_led2off() {
  LED2status = LOW;
  server.send(200, "text/html", SendHTML(LED1status,false,LCDstatus)); 
}

void handle_lcdon() {
  LCDstatus = HIGH;
  server.send(200, "text/html", SendHTML(LED1status,LED2status,true)); 
}
void handle_lcdoff() {
  LCDstatus = LOW;
  server.send(200, "text/html", SendHTML(LED1status,LED2status,false)); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String SendHTML(uint8_t led1stat,uint8_t led2stat,uint8_t lcdstat){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>LED Control</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr +=".button {display: block;width: 80px;background-color: #1abc9c;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr +=".button-on {background-color: #1abc9c;}\n";
  ptr +=".button-on:active {background-color: #16a085;}\n";
  ptr +=".button-off {background-color: #34495e;}\n";
  ptr +=".button-off:active {background-color: #2c3e50;}\n";
  ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>ESP8266 Web Server</h1>\n";
  ptr +="<h3>Using Access Point(AP) Mode</h3>\n";
  
   if(led1stat)
  {ptr +="<p>LED1 Status: ON</p><a class=\"button button-off\" href=\"/led1off\">OFF</a>\n";}
  else
  {ptr +="<p>LED1 Status: OFF</p><a class=\"button button-on\" href=\"/led1on\">ON</a>\n";}

  if(led2stat)
  {ptr +="<p>LED2 Status: ON</p><a class=\"button button-off\" href=\"/led2off\">OFF</a>\n";}
  else
  {ptr +="<p>LED2 Status: OFF</p><a class=\"button button-on\" href=\"/led2on\">ON</a>\n";}
  
  if(lcdstat)
   {ptr +="<p>LCD Status: ON</p><a class=\"button button-off\" href=\"/lcdoff\">OFF</a>\n";}
  else
  {ptr +="<p>LCD Status: OFF</p><a class=\"button button-on\" href=\"/lcdon\">ON</a>\n";}

  
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
