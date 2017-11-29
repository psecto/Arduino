/**
* @license
* Copyright © 2017 Psecto, Psecto Productions ltd, Mihai FLOARES
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of this Software and associated documentation files (the "Software"), 
* to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
* and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
* 
* The Software is provided "as is", without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, 
* fitness for a particular purpose and noninfringement. In no event shall the authors or copyright holders be liable for any claim, damages or other liability, 
* whether in an action of contract, tort or otherwise, arising from, out of or in connection with the Software or the use or other dealings in the Software.
* 
* Except as contained in this notice, the name of Psecto shall not be used in advertising or otherwise to promote the sale, 
* use or other dealings in this Software without prior written authorization from Psecto, PsecTo Productions A.K.A. Mihai FLOARES.
*/

//NODEMCU board and LEGO TECHNICS project

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
