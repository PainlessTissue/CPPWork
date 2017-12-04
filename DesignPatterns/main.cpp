#include "OBS_WeatherObject.h"
#include "OBS_BasicDisplay.h"

#include "Trace.h"
#include <iostream>
#include <string>


int main()
{
	WeatherObject *obj = new BasicDisplay();

	obj->addWeatherObject(obj);
	
}