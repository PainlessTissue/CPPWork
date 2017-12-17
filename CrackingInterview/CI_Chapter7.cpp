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

#include <time.h>

JigsawPiece::JigsawPiece()
	:northPiece(0), southPiece(0), eastPiece(0), westPiece(0), inserted(false)
{
	//this counter variable makes sure a single piece never has more than 2 closed spots
	int numClosed = 0;
	int rander = (rand() % 3); //create random number

	if (rander == 2) //if the random variable is 2 (closed), increment the counter
		numClosed++;

	northSlot = (JigsawSlot)(rander); //assign the random number

	rander = (rand() % 3); //create a new random number

	if (rander == 2)
		numClosed++;

	southSlot = (JigsawSlot)(rander);

	rander = (rand() % 3); 

	//at this point it is possible to have more than two closed spots,
	//which is why we test if it is currently 2
	if (rander == 2) 
	{
		while (rander == 2 && numClosed >= 2) //if it is 2, and we already have two closed spots
			rander = (rand() % 3); //keep making new variables until it isnt 2
		
		numClosed++; //increment 
	}
	
	eastSlot = (JigsawSlot)(rander);
	
	rander = (rand() % 3); 
	
	while (rander == 2 && numClosed >= 2) //if the number is 2 AND we have too many closed slots
		rander = (rand() % 3); //keep making new numbers
	
	westSlot = (JigsawSlot)(rander);
}

#include <iostream>
using std::cout;
using std::endl;

void JigsawPiece::printSlot()
{
	cout << (int)this->northSlot << ", " << (int)this->southSlot << ", "
		<< (int)this->eastSlot <<  ", " << (int)this->westSlot << endl;

}

JigsawPuzzle::JigsawPuzzle()
{
	//shut up warning 
#pragma warning (push)
#pragma warning (disable:4244)
	srand(time(NULL)); //reset the seed so we always have a new puzzle
#pragma warning (pop)

	//create a bunch of pieces
	beginning = new LinkedList<JigsawPiece>[COLSIZE * ROWSIZE];

	//printInfo(beginning);

	
	for (int i = 0; i < COLSIZE * ROWSIZE; i++)
	{

	}
}

bool JigsawPuzzle::fitsWith(int firstPiece, int secondPiece)
{
	//safety to be sure the pieces in question are valid numbers
	if (firstPiece <= ROWSIZE * COLSIZE && secondPiece <= ROWSIZE * COLSIZE)
	{
		if (beginning[firstPiece].item->northSlot == JigsawSlot::out &&
			beginning[secondPiece].item->southSlot == JigsawSlot::in)
			return true;

		else if (beginning[firstPiece].item->southSlot == JigsawSlot::out &&
			beginning[secondPiece].item->northSlot == JigsawSlot::in)
			return true;
	}

	return false;
}

void JigsawPuzzle::printInfo(LinkedList<JigsawPiece> *head)
{
	for (int i = 0; i < COLSIZE * ROWSIZE; i++)
	{
		beginning[i].item->printSlot();
	}

	std::cin.ignore();
}
