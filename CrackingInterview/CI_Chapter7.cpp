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
	
}
