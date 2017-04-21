/*
 Name:		LaserTripwireLib.h
 Created:	4/21/2017 6:05:35 PM
 Author:	johnnaras
 Editor:	http://www.visualmicro.com
*/

#ifndef _LaserTripwireLib_h
#define _LaserTripwireLib_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

enum photoResistorStatus { LIGHT, DARK };

class Laser {
private:
	uint8_t pinLaser;
public:
	Laser(uint8_t);
	void activate();
	void deactivate();
};

class PhotoResistor {
private:
	uint8_t pinPhotoResistor;
public:
	PhotoResistor(uint8_t);
	photoResistorStatus status();
};

class LaserTripwire {
private:
	Laser laser;
	PhotoResistor photoResistor;
public:
	LaserTripwire(uint8_t, uint8_t);
	bool isBroken();
};

#endif

