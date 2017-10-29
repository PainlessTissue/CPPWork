#include "Chapter2.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Chapter2::Chapter2() {}
Chapter2::~Chapter2() {}


void Chapter2::question1()
{
	int fifty = 50;
	int oneHundred = 100;

	int total = fifty + oneHundred;

	Trace::out("Total: %i", total);
}

void Chapter2::question2()
{
	const float INCOMEPERCENT = .58f;

	float companyIncome = 0.0f;
	cout << "List company's revenue" << endl;
	cin >> companyIncome;

	Trace::out("Your total income is: %f \n", companyIncome * INCOMEPERCENT);

}

void Chapter2::question3()
{
	const float COUNTYTAX(0.02f), SALESTAX(0.04f);

	float itemCost(0.0f);
	cout << "Enter purchase cost" << endl;
	cin >> itemCost;

	Trace::out("Total item cost: %.2f\n", itemCost + (itemCost * COUNTYTAX * SALESTAX));
	Trace::out("Tax amount: %.2f\n", itemCost * COUNTYTAX * SALESTAX);
}

void Chapter2::question4()
{
	const float TAX(.0675f);

	float bill(0.0f);
	cout << "Enter bill cost: \n";
	cin >> bill;

	Trace::out(
		"Meal cost: %.2f\n"
		"Tax amount %.2f\n"
		"Tip amount %.2f\n"
		"Total bill: %.2f\n",
		bill,
		bill * TAX,
		(bill + bill * TAX) * .2f,
		bill + (bill * TAX) + (bill + bill * TAX) * .2f);
}

void Chapter2::question5()
{
	float usersNumber(0.0f), addedNumbers(0.0f);
	int numbersEntered(0);

	cout << "Enter a series of numbers, to end, enter 0\n";

	while (true)
	{
		cout << "Enter a number\n";
		cin >> usersNumber;

		if (usersNumber != 0)
		{
			numbersEntered++;
			addedNumbers += usersNumber;
		}

		else
			break;
	}

	Trace::out("Final number: %f\n", addedNumbers / numbersEntered);
}
