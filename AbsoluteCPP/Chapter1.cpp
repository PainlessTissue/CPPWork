#include <iostream>

#include "Chapter1.h"
#include "Trace.h"

using std::cout;
using std::cin;

Chapter1::Chapter1() {}
Chapter1::~Chapter1() {}

void Chapter1::question1()
{
	float inputWeight(0.0f);
	cout << "What is the weight of your cereal in ounces?\n";
	cin >> inputWeight;

	//35273.92 is given by the problem
	Trace::out("That is %.2f ounces. \n", inputWeight / 35273.92);
	Trace::out("The necessary amount of this cereal to equal a metric ton is %.2f", 35273.92 / inputWeight);
}

void Chapter1::question2()
{
	const float artificalSweetner = .001f; //given by problem
	float mouseWeight;
	float killAmount;
	float weightDieter;
	float targetWeight;

	cout << "How much does the mouse weigh?\n";
	cin >> mouseWeight;

	cout << "How much does it take to kill a mouse?\n";
	cin >> killAmount;

	cout << "How much do you weigh\n";
	cin >> weightDieter;

	cout << "What is your target weight to lose?\n";
	cin >> targetWeight;
}

void Chapter1::question3()
{
	const float payIncrease = 1.0076f; //given by problem
	float prevAnnualSalary;

	cout << "What is your current annual salary?\n";
	cin >> prevAnnualSalary;

	float currAnnualSalary = prevAnnualSalary * payIncrease;

	Trace::out("Your new annual salary is %.2f and your monthly is %.2f ", currAnnualSalary, currAnnualSalary / 12);
}

void Chapter1::question4()
{
	float neededAmount;
	float interestRate;
	float duration;

	cout << "How much money do you need?\n";
	cin >> neededAmount;

	cout << "Whats the interest rate \n";
	cin >> interestRate;

	cout << "Whats the duration youll be paying\n";
	cin >> duration;

	Trace::out("Youll be paying %.2f annually and %.2f monthly",  (neededAmount * interestRate) * duration, (neededAmount * interestRate) * duration / 12);
}

void Chapter1::question5()
{
	const int maxRoomCapacity = 25;
	int currentRoomCapacity = 0;

	cout << "How many people are going to be in the room?\n";
	cin >> currentRoomCapacity;

	//if its legal
	if (currentRoomCapacity <= maxRoomCapacity)
		Trace::out("Fire expectiations are met, you may fit %i more people if you so please\n", maxRoomCapacity - currentRoomCapacity);

	//illegal
	else
		Trace::out("Current room capacity is too large, please remove %i people to meet fire safety", currentRoomCapacity - maxRoomCapacity);
}

void Chapter1::question6()
{
	int hoursWorked, dependencies;

	cout << "How many hours did you work this week?\n";
	cin >> hoursWorked;
	cout << "How many dependencies do you have?\n";
	cin >> dependencies;

	const float HOURLYPAY = 16.78f; //given by problem

	float pay = 0;

	if (hoursWorked > 40)//overtime pay
	{
		pay = (hoursWorked - 40) * HOURLYPAY * 1.5f;
		pay += HOURLYPAY * 40;
	}

	else //regular pay
		pay = hoursWorked * HOURLYPAY;

	Trace::out("Gross pay: %.2f\n", pay);

	//taxes
	float socialSecurity = pay - (pay * .06f);

	Trace::out("Social Security tax: %.2f\n" , pay - socialSecurity);

	socialSecurity = pay - socialSecurity;

	float federalIncome = pay - (pay * .14f);

	Trace::out("Federal Income Tax: %.2f\n", pay - federalIncome);

	federalIncome = pay - federalIncome;

	float state = pay - (pay * .05f);

	Trace::out("State Income Tax: %.2f\n", pay - state);

	state = pay - state;

	pay -= 10; //union dues

	Trace::out("Union dues cost 10 bucks\n");

	if (dependencies >= 3) //if worker has 3 or more depencies (given by problem)
	{
		pay -= 35;

		Trace::out("Dependencies for health care cost 35 dollars\n");
	}



	Trace::out("Final pay: %.2f", pay - socialSecurity - federalIncome - state);
}

void Chapter1::question7(int weight, int METS, int minutes)
{
	float caloriesPerMin = .0175f * METS * weight;

	Trace::out("Your calories per min: %.2f" ,caloriesPerMin);
}

void Chapter1::question8(float n)
{
	int count = 0;
	float guess;

	do
	{
		guess = 5;
		float r = n / guess;
		guess = (guess + r) / 2;

	} while (count++ < 10);

	Trace::out("%.2f", guess);
}

void Chapter1::question11()
{
	int timeInSeconds;
	int minutes = 0;
	int hours = 0;
	int seconds = 0;

	cout << "How many seconds\n";
	cin >> timeInSeconds;

	minutes = timeInSeconds / 60;
	seconds = timeInSeconds % 60;
	hours = minutes / 60;
	minutes = minutes % 60;

	Trace::out("Hours = %i\nMinutes = %i\nSeconds = %i", hours, minutes, seconds);
}
