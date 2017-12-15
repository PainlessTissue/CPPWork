#pragma once
class FACT_CardGame
{
public:
	FACT_CardGame();
	~FACT_CardGame();
};

//question 1: design a generic deck of cards, 
//explain how you could subclass it into a game of blackjack

enum class CardType
{
	//corresponding card types
	ace,
	two,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine,
	ten,
	jack,
	queen,
	king
};

enum class CardGameType
{
	Poker,
	BlackJack
};

class Card
{
	Card(); //singleton constructor to make sure there is never more than 4 of a card
	CardType cardType;

public:
};

class CardGame
{
public:
	CardGame* createCardType(CardGameType cardGame);

};

class BlackJackGame
{

};

class PokerGame
{

};