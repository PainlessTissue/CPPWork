#ifndef WEATHEROBJECT_H
#define WEATHEROBJECT_H

class WeatherObject;
class WeatherList;

//observer design pattern
class WeatherObject
{
	//data
	float temp, humidity, pressure;
	WeatherList *head, *tail;
	
	//helper functions
	void getNewData(); //this function is just to simulate if there was something to observe (satelite for example)
	void updateObservers(); 

public:
	WeatherObject();
	virtual ~WeatherObject();

	void addWeatherObject(WeatherObject *newObj);
	void removeWeatherObject(WeatherObject *deleteObj);
	void cleanUp(); //delete method

	//accessors
	float getTemp() { return temp; }
	float getHumdity() { return humidity; }
	float getPressure() { return pressure; }
	
	void setTemp(float newTemp) { this->temp = newTemp; }
	void setHumidity(float newHumidity) { this->humidity = newHumidity; }
	void setPressure(float newPressure) { this->pressure = newPressure; }

	//this is the method all are required to implement for the observer pattern
	virtual void update(float temp, float humidity, float pressure) = 0;

};

//class strictly for holding all the observers
class WeatherList
{
	WeatherList *next, *prev;
	WeatherObject *obj;

public:
	WeatherList(WeatherObject *obj)
		:next(0), prev(0), obj(obj) {}
	virtual ~WeatherList() { delete obj; }

	void setNext(WeatherList *newNext) { this->next = newNext; }
	void setPrev(WeatherList *newPrev) { this->prev = newPrev; }
	WeatherList *getNext() { return next; }
	WeatherList *getPrev() { return prev; }

	WeatherObject *getWeatherObject() { return obj; }
};

#endif // !WEATHEROBJECT_H
