/**
* Copyright © 2017 Psecto, Psecto Productions ltd, Mihai FLOARES
*/

//NODEMCU Development board and LEGO TECHNICS WiFi Controlled Robotic Arm project 

//Include wifi library

#include <ESP8266WiFi.h>

//Setup the Wifi connection

const char* ssid = "name";  /WiFi name
const char* password = "password"; /WiFi password
WiFiServer server(80);

//Pin initialization (init)

//Claw Pin init
  int Claw1 = 2; // D4
  int Claw2 = 14; // D5
  int ClawSwitch = 12; // D6
//Piston Pin init
  int Piston1 = 5; // D1
  int Piston2 = 4; // D2
  int PistonSwitch = 0; //D3

//Open Comms and declare Pins

void setup() {
  Serial.begin(115200);
  delay(10);

//Declare Pin Type

  //Claw
  pinMode(Claw1, OUTPUT);
  pinMode(Claw2, OUTPUT);
  pinMode(ClawSwitch, OUTPUT);
  //Piston
  pinMode(Piston1, OUTPUT);
  pinMode(Piston2, OUTPUT);
  pinMode(PistonSwitch, OUTPUT);

//Declare init Pin State

  //Claw
  digitalWrite(Claw1, LOW);
  digitalWrite(Claw2, LOW);
  digitalWrite(ClawSwitch, LOW);
  //Piston
  digitalWrite(Piston1, LOW);
  digitalWrite(Piston2, LOW);
  digitalWrite(PistonSwitch, LOW);
 
 
// Connect to WiFi network

  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
 }
    
// Start the server

  server.begin();
  
}
 
void loop() {
// Check if a client has connected
  
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
// Read the first line of the request

  String request = client.readStringUntil('\r');
  client.flush();
 
// Match the request
 
  if (request.indexOf("/ClawRelease") != -1)  {
      digitalWrite(Claw1, LOW);
      digitalWrite(Claw2, HIGH);    
      digitalWrite(ClawSwitch, HIGH);
      delay(2000);
      digitalWrite(ClawSwitch, LOW);
  }
  
 if (request.indexOf("/ClawGrab") != -1)  {
      digitalWrite(Claw1, HIGH);
      digitalWrite(Claw2, LOW);    
      digitalWrite(ClawSwitch, HIGH);
      delay(2000);
      digitalWrite(ClawSwitch, LOW);
 }
  
  if (request.indexOf("/PistonUp") != -1)  {
      digitalWrite(Piston1, LOW);
      digitalWrite(Piston2, HIGH);    
      digitalWrite(PistonSwitch, HIGH);
      delay(2000);
    digitalWrite(PistonSwitch, LOW);
  }
   
  if (request.indexOf("/PistonDown") != -1)  {
      digitalWrite(Piston1, HIGH);
      digitalWrite(Piston2, LOW);    
      digitalWrite(PistonSwitch, HIGH);
      delay(2000);
      digitalWrite(PistonSwitch, LOW);
  }
 

}

/**
 
WARNING: the code has reply, meaning that it will receive a request (ping) but not send a reply (pong) in return. 
Some OS (iPad for example) will attempt to sent 3 times the same request waiting for a reply 

*/
