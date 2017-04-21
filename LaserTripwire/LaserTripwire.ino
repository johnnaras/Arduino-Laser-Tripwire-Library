/*
 Name:		LaserTripwire.ino
 Created:	4/21/2017 6:05:35 PM
 Author:	Ioannis
 Editor:	http://www.visualmicro.com
*/

#include "LaserTripwireLib.h"

LaserTripwire lt(7, A0);

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() {
	if (lt.isBroken()) Serial.println("Thief!");
	else Serial.println("All OK.");
	delay(1000);
}
