#include "OBS_BasicDisplay.h"



BasicDisplay::BasicDisplay()
{
}


BasicDisplay::~BasicDisplay()
{
}

void BasicDisplay::updateAll(float temp, float humidity, float pressure)
{
	setHumidity(humidity);
	setPressure(pressure);
	setTemp(temp);
}

void BasicDisplay::update(float temp, float humidity, float pressure)
{
	updateAll(temp, humidity, pressure);
}
