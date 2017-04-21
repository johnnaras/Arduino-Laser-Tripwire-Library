/*
 Name:		LaserTripwireLib.cpp
 Created:	4/21/2017 6:05:35 PM
 Author:	johnnaras
 Materials:	1 x Arduino, 1 x photo-resistor, 1 x 10kOhm resistor, 1 laser 5V
 Conncetions:	Connect the photo-resistor to an analog input and 5V. Connect the 10kOhm resistor to the same analog input
				as the photo-resistor and GND. Connect the 5V laser to a digital pin and GND.
 Usage:		Create a LaserTripwire object and use its isBroken() method to check the laser beam status.
*/

#include "LaserTripwireLib.h"

///<summary>Constructor of a laser object.</summary>
///<param name="pin">Digital output pin on Arduino.</param>
Laser::Laser(uint8_t pin)
{
	pinLaser = pin;
	pinMode(pin, OUTPUT);
}

///<summary>Activates the laser beam.</summary>
void Laser::activate()
{
	digitalWrite(pinLaser, HIGH);
}

///<summary>Deactivates the laser beam.</summary>
void Laser::deactivate()
{
	digitalWrite(pinLaser, LOW);
}

///<summary>Constructor of a photo-resistor object.</summary>
///<param name="pin">Analog input pin on Arduino.</param>
PhotoResistor::PhotoResistor(uint8_t pin)
{
	pinPhotoResistor = pin;
	pinMode(pin, INPUT);
}

///<summary>Reads the input from the photo-resistor and returns accordingly.</summary>
///<returns>LIGHT if the photo-resistor gets light.</returns>
///<returns>DARK if the photo-resistor gets no light.</returns>
photoResistorStatus PhotoResistor::status()
{
	return analogRead(pinPhotoResistor) > 100 ? LIGHT : DARK;
}

///<summary>Constructor of a tripwire object.</summary>
///<param name="pinL">Digital input pin on Arduino, to connect the laser.</param>
///<param name="pinP">Analog input pin on Arduino, to connect the photo-resistor.</param>
LaserTripwire::LaserTripwire(uint8_t pinL, uint8_t pinP) :laser(pinL), photoResistor(pinP) {};

///<summary>Activates the laser beam and then reads the input of the photo-resistor. Returns accordingly.</summary>
///<returns>TRUE, if the laser beam is broken.</returns>
///<returns>FALSE, if the laser beam  is working.</returns>
bool LaserTripwire::isBroken()
{
	laser.activate();
	photoResistorStatus temp = photoResistor.status();
	laser.deactivate();
	return (temp==DARK)?true:false;
}
