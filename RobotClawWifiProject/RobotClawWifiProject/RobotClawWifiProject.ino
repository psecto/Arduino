/**
****************************************************************************************************
Name:		RobotClawWifiProject.ino
Created:	12/1/2017 11:01:11 PM
Author:		Mihai Floares
About:		NODEMCU WIFI Development board + LEGO TECHNICS - WIFI Controlled Robotic Arm project

Copyright © 2017 - Psecto Productions ltd.
*****************************************************************************************************
*/
//Include WiFi library

#include <ESP8266WiFi.h>

//Setup the Wifi connection

const char* ssid = "yourssidname"; // WiFi name
const char* password = "yourssidpassword"; // WiFi password
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

//Leds Pin init
int LED1 = 13; //D7 (2 pin remaining D8 = 15 , D0=16) 


//Open Comms and declare Pins

void setup() {
	Serial.begin(115200);
	delay(10);

	//Declare Pin Type

	//LEDs
	pinMode(LED1, OUTPUT);

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
	//LED
	digitalWrite(LED1, LOW);
	
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

	if (request.indexOf("/ClawRelease") != -1) {
		digitalWrite(Claw1, LOW);
		digitalWrite(Claw2, HIGH);
		digitalWrite(ClawSwitch, HIGH);
		digitalWrite(LED1, HIGH);
		delay(2000);
		digitalWrite(ClawSwitch, LOW);
		digitalWrite(LED1, LOW);
	}

	if (request.indexOf("/ClawGrab") != -1) {
		digitalWrite(Claw1, HIGH);
		digitalWrite(Claw2, LOW);
		digitalWrite(ClawSwitch, HIGH);
		digitalWrite(LED1, HIGH);
		delay(2000);
		digitalWrite(ClawSwitch, LOW);
		digitalWrite(LED1, LOW);
	}

	if (request.indexOf("/PistonUp") != -1) {
		digitalWrite(Piston1, LOW);
		digitalWrite(Piston2, HIGH);
		digitalWrite(PistonSwitch, HIGH);
		digitalWrite(LED1, HIGH);
		delay(2000);
		digitalWrite(PistonSwitch, LOW);
		digitalWrite(LED1, LOW);
	}

	if (request.indexOf("/PistonDown") != -1) {
		digitalWrite(Piston1, HIGH);
		digitalWrite(Piston2, LOW);
		digitalWrite(PistonSwitch, HIGH);
		digitalWrite(LED1, HIGH);
		delay(2000);
		digitalWrite(PistonSwitch, LOW);
		digitalWrite(LED1, LOW);
	}


}
