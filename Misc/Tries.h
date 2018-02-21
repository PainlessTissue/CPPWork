#pragma once
class Tries
{
public:
	Tries();
	~Tries();
};

/*
my idea is to represent phone numbers using a trie structure
all nodes will inherit from the generic interface "Digit"
and all the information will be stored in the final node at the bottom
*/

//virtual interface class for inheriting
class Digit
{
	
};


class GenericDigit : public Digit
{

};


class FinalDigti : public Digit
{

};