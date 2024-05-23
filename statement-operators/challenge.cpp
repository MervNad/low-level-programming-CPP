/***********************************************************************************
*file: challenge.cpp
*Description: Write a program  that asks the user to enter the following:
*			  an integer  representing the number of cents.
*			  Assume that the number of cents entered is greater than or equal to 0.
*			  The program should then display how to provide that change to the user.
*			  
*			  In the US: 
*			  1$ is 100 cents.
*			  1 quater is 25 cents.
*			  1 dime is 10 cents.
*			  1 nickel is 5 cents.
*			  1 penny is 1 cent.
*
*Pseudocode:
****************************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int dollar{},quater{},dime{},nickel{},penny{},cents{}, remainder{};
	cout << "Enter an amount in cents: ";
	cin >> cents;
	
	if (cents >= 100)
	{
		dollar = cents / 100;
		remainder = cents % 100;
		if (remainder >= 25 && remainder < 100)
		{
			quater = remainder / 25;
			remainder = remainder % 25;
			if (remainder >= 10 && remainder < 25)
			{
				dime = remainder / 10;
				remainder = remainder % 10;
				if (remainder >= 5 && remainder < 10)
				{
					nickel = remainder / 5;
					remainder = remainder % 5;
					penny = remainder;
				}
			}
		}
		else
		{
			if (remainder >= 10 && remainder < 25)
			{
				dime = remainder / 10;
				remainder = remainder % 10;
				if (remainder >= 5 && remainder < 10)
				{
					nickel = remainder / 5;
					remainder = remainder % 5;
					penny = remainder;
				}
				else
				{
					penny = remainder;
				}
			}
			else
			{
				if (remainder >= 5 && remainder < 10)
				{
					nickel = remainder / 5;
					remainder = remainder % 5;
					penny = remainder;
				}
				else
				{
					penny = remainder;
				}
			}
		}
	}
	else
	{
		if (cents >= 25 && cents < 100)
		{
			quater = cents / 25;
			remainder = cents % 25;
			if (remainder >= 10)
			{
				dime = remainder / 10;
				remainder = remainder % 10;
				if (remainder >= 5)
				{
					nickel = remainder / 5;
					remainder = remainder % 5;
					penny = remainder;
				}
				else
				{
					penny = remainder;
				}
			}
				
			else
			{
				if (remainder >= 5)
				{
					nickel = remainder / 5;
					remainder = remainder % 5;
					penny = remainder;
				}
				else
				{
					penny = remainder;
				}
			}
		}				
		else
		{
			if (cents >= 10 && cents < 25)
			{
				dime = cents / 10;
				remainder = cents % 10;
				if (remainder >= 5)
				{
					nickel = remainder / 5;
					remainder = remainder % 5;
					penny = remainder;
				}
				else
				{
					penny = remainder;
				}
			}
			else
			{
				if (cents >= 5 && cents < 10)
				{
					nickel = cents / 5;
					remainder = cents % 5;
					penny = remainder;
				}
				else
				{
					penny = cents;
				}
			}
		}
	}
	
	cout << "You can provide change for this amount as follow: " << endl;
	cout <<"dollars: " << dollar << endl;
	cout <<"quaters: " << quater << endl;
	cout <<"dimes: " << dime << endl;
	cout <<"nickels: " << nickel << endl;
	cout <<"pennies: " << penny << endl;
	return 0;
}