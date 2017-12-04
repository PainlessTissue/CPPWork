#ifndef PIZZA_H
#define PIZZA_H 


#include <string.h>
#include <iostream>
using std::string;

//abstract pizza class
class Pizza
{
public:
	Pizza() {}

	virtual ~Pizza() = default;

	virtual float getCost() { return cost; }
	virtual void setCost(float newCost) { cost = newCost; }
	
	virtual string getName() { return name; }
	virtual void setName(string newName) { name = newName; }
	
private:
	string name;
	float cost;
};

class CheesePizza : public Pizza
{
public:
	CheesePizza();
	virtual ~CheesePizza() = default;
};



#endif // !PIZZA_H
