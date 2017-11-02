#include "Chapter2.h"
#include <iostream>
#include <string>

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

void Chapter2::question7()
{
	const float SEA_LEVEL_RISE = 1.5f;

	Trace::out("Sea level will rise %.2f milimeters in 5 years", SEA_LEVEL_RISE * 5);
	Trace::out("Sea level will rise %.2f milimeters in 7 years", SEA_LEVEL_RISE * 7);
	Trace::out("Sea level will rise %.2f milimeters in 10 years", SEA_LEVEL_RISE * 10);
}

void Chapter2::question16(int sizeOfTriangle)
{
	//im required to use cout instead of trace::out due to the way trace works
	for (int i = 0; i <= sizeOfTriangle; i++)
	{
		cout << std::string(i, '*') << endl;
	}

	for (int i = sizeOfTriangle - 1; i >= 0; i--)
	{
		cout << std::string(i, '*') << endl;
	}
	cin.ignore(); //to show the triangle
}