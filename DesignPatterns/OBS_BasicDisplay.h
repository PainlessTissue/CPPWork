#ifndef BASIC_DISPLAY_H
#define BASIC_DISPLAY_H

#include "OBS_WeatherObject.h"

class BasicDisplay : public WeatherObject
{
public:
	BasicDisplay();
	~BasicDisplay();

	void updateAll(float temp, float humidity, float pressure);

	virtual void update(float temp, float humidity, float pressure) override;
};

#endif // !BASIC_DISPLAY_H
