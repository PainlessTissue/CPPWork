#ifndef COND_H
#define COND_H

#include "DEC_Pizza.h"

class Condiment : public Pizza
{
public:
	Condiment();
	virtual ~Condiment() { delete piz; }

	virtual string getDescription() = 0;
	virtual Pizza* getPiz() { return piz; }
	virtual void setPiz(Pizza *piz) { this->piz = piz; }

private:
	string description;
	Pizza *piz;

};

class Pep : public Condiment
{
public:
	Pep(Pizza *piz);

	string getDescription() override;
	float getCost() override;

};

class Sausage : public Condiment
{
public:
	Sausage(Pizza *piz);

	string getDescription() override;
	float getCost() override;
};


#endif // !COND_H
