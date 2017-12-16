#include "CI_Chapter7.h"

//question 2
void AvaliableEmployees::dispatchCall()
{
	if (avaliableRespondants.size() > 0)
		getAvaliableRespondant();

	else if (avaliableManager.size() > 0)
		getAvaliableManager();

	else
		getAvaliableDirector();
}

Respondent AvaliableEmployees::getAvaliableRespondant()
{
	Respondent r = avaliableRespondants.front();
	avaliableDirector.pop();

	return r;
}

Manager AvaliableEmployees::getAvaliableManager()
{
	Manager m = avaliableManager.front();
	avaliableManager.pop();

	return m;
}

Director AvaliableEmployees::getAvaliableDirector()
{
	Director d = avaliableDirector.front();
	avaliableDirector.pop();

	return d;
}




//question 3

template<typename Song>
void JukeBox<Song>::addSongToList(Song song)
{
	LinkedList *newList = new LinkedList[listSize + 1];

	for (int i = 0; i < listSize; i++)
		newList[i] = this->list[i]; //copy the data over the new list

	newList[listSize + 1] = song; //add in the new song
}

template<typename Song>
void JukeBox<Song>::removeSongFromList(Song * song)
{
	(void*)song; //get rid of errors
}



//question 4

//static variable declerations
ParkingGarage *ParkingGarage::instance = 0;
int ParkingGarage::numParkingSpotsOpen = 0;

ParkingGarage * ParkingGarage::createParkingGarage()
{
	if (instance == 0)
	{
		instance = new ParkingGarage;
		//allocate how ever many parking spots there will be in the garage
		instance->parkingSpots = new LinkedList<ParkingSpot>[NUMSPOTS]; 

		//setting the head node
		instance->parkingSpots[0].prev = 0; 
		instance->parkingSpots[0].next = &instance->parkingSpots[1];
		instance->parkingSpots[0].item->setId(0);

		//this does all the setting for the other nodes throughout the parking lot
		//giving them their id numbers and setting the prev and next for the 
		for (int i = 1; i < NUMSPOTS; i++)
		{
			//i got rid of the prev and next assignments because, for parking lots
			//there isnt really any form of linkage, just numbers, which can be accessed through their id
			
			//instance->parkingSpots[i].prev = &instance->parkingSpots[i - 1]; //set the prev
			//instance->parkingSpots[i].next = &instance->parkingSpots[i + 1]; //set the next 
			
			instance->parkingSpots[i].item->setId(i); //set the id
		}
	}

	instance->parkingSpots[NUMSPOTS - 1].next = 0;

	return instance;
}

void ParkingSpot::setUnavaliable()
{
	this->avaliable = false;
}

void ParkingSpot::setAvaliable()
{
	this->avaliable = true;
}
