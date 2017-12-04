#include "OBS_WeatherObject.h"

void WeatherObject::getNewData()
{

}

void WeatherObject::updateObservers()
{
	//go through the list and update every object
	for (WeatherList *iter(head); iter; iter = iter->getNext())
		iter->getWeatherObject()->update(temp, humidity, pressure);
	
}

WeatherObject::WeatherObject()
{
	getNewData();

	updateObservers();
}

WeatherObject::~WeatherObject()
{
}

void WeatherObject::addWeatherObject(WeatherObject * newObj)
{
	WeatherList *tmp = new WeatherList(newObj);

	if (head == 0)
	{
		head = tmp;
		tail = tmp;
	}

	else
	{
		tmp->setNext(head);
		head->setPrev(tmp);

		head = tmp;
	}

	//keep the data updated
	newObj->update(temp, humidity, pressure);
}

void WeatherObject::removeWeatherObject(WeatherObject * deleteObj)
{
	WeatherList *headIter(head), *tailIter(tail);

	if (tail->getWeatherObject() == deleteObj && head->getWeatherObject() == deleteObj) //only one thing in list
	{
		delete deleteObj;
		
		head = 0;
		tail = 0;

		return;
	}

	while (headIter && tailIter)
	{
		if (headIter->getWeatherObject() == deleteObj) //head found it
		{
			if (headIter->getPrev() == 0) //beginning of list, deleteObj == head
			{
				head = headIter->getNext(); //set the head to the current heads next
				headIter->getNext()->setPrev(0); //set next to 0 (since it the head)

				delete headIter;
			}

			else if (tailIter->getNext() && tailIter->getPrev()) //middle of list
			{
				headIter->getNext()->setPrev(headIter->getPrev());
				headIter->getPrev()->setNext(headIter->getNext());

				delete headIter;
			}

			break;
		}


		else if (tailIter->getWeatherObject() == deleteObj) //tail found it
		{
			if (tailIter->getNext() == 0) //end of list, deleteObj == tail
			{
				tail = tailIter->getPrev(); //set the tail to the current tails prev
				tailIter->getPrev()->setNext(0); //set prev to 0 (now that its the tail)

				delete tailIter;
			}

			else if (tailIter->getNext() && tailIter->getPrev()) //middle of list
			{
				tailIter->getNext()->setPrev(tailIter->getPrev());
				tailIter->getPrev()->setNext(tailIter->getNext());
				
				delete tailIter;
			}

			break;
		}

		//advance
		headIter = headIter->getNext();
		tailIter = tailIter->getPrev();
	}
}

void WeatherObject::cleanUp()
{
	WeatherList *tmpNext;

	for (WeatherList *iter = head; iter; iter = iter->getNext())
	{
		tmpNext = iter->getNext();

		//delete iter->getWeatherObject(); //delete the weather object itself
		delete iter; //and the linked list

		iter = tmpNext;
	}
}
