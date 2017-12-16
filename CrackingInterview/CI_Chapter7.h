#include <queue>
#include <list>
#include <string>
using std::queue;
using std::list;
using std::string;

class CI_Chapter7 //oo design
{
};

//i created my own linked list for this because I find basic stl unsatisfactory
template <typename T>
struct LinkedList
{
	LinkedList *next, *prev;

	T find(T find, LinkedList<T> *head)
	{
		for(LinkedList<T> *iter = head; iter != 0; iter = iter->next)
		{ 
			if (iter == find)
				return iter;
		}

		return 0;
	}
};

//question 1 can be found in design patterns project (factory)
//question 1: design a generic deck of cards,
//explain how it could be implemented as blackjack

/*
question 2: you have three levels of employes: respondent, manager, and director
if a call comes in, it must go to a respondant, then manager, then director (if lower cant answer it)
it is supplied like a first in, first out on who answers the phone 
*/

// forward declerations
class Respondent {};
class Manager {};
class Director {};
class AvaliableEmployees;

class AvaliableEmployees 
{
	queue<Respondent> avaliableRespondants;
	queue<Manager> avaliableManager;
	queue<Director> avaliableDirector;

public:
	void dispatchCall()
	{
		if (avaliableRespondants.size() > 0)
			getAvaliableRespondant();

		else if (avaliableManager.size() > 0)
			getAvaliableManager();
		
		else
			getAvaliableDirector();
	}

	Respondent getAvaliableRespondant() 
	{ 
		Respondent r = avaliableRespondants.front();
		avaliableDirector.pop();

		return r;
	}

	Manager getAvaliableManager()
	{
		Manager m = avaliableManager.front();
		avaliableManager.pop();

		return m;
	}

	Director getAvaliableDirector()
	{
		Director d = avaliableDirector.front();
		avaliableDirector.pop();

		return d;
	}
};

//question 3: implement a jukebox
template <class Song>
class JukeBox
{
	LinkedList<Song> *list; //a jukebox has a list of songs
	int listSize;

public:
	void playSong(Song *song) { song->playSong(); }
	void playRandomSong() { list[rand() % listSize]->playSong(); }
};

class Song
{
	string title;
	string artistName;
	int length; //song length

public:
	void playSong() {}
};
