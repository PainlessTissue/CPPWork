#include "DEC_Condiment.h"


Condiment::Condiment()
{
}



Pep::Pep(Pizza * piz)
{
	setPiz(piz);
}

string Pep::getDescription()
{
	return this->getPiz()->getName() + ", Pepperoni";
}

float Pep::getCost()
{
	return this->getPiz()->getCost() + 1.99f;
}

Sausage::Sausage(Pizza * piz)
{
	setPiz(piz);
}

string Sausage::getDescription()
{
	return getPiz()->getName() + ", Sausage";
}

float Sausage::getCost()
{
	return getPiz()->getCost() + 1.50f;
}
