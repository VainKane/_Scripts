#include <iostream>

using namespace std;

int main()
{
	int bacChoice;
	int namChoice;

	cin >> bacChoice >> namChoice;
	
	if (bacChoice == namChoice)
	{
		cout << "HOA";
	}
	
	else if (bacChoice == 0)
	{
		if (namChoice == 1)
		{
			cout << "BAC";
		}
		else
		{
			cout << "NAM";
		}
	}

	else if (bacChoice == 1)
	{
		if (namChoice == 2)
		{
			cout << "BAC";
		}
		else
		{
			cout << "NAM";
		}
	}

	else if (bacChoice == 2)
	{
		if (namChoice == 0)
		{
			cout << "BAC";
		}
		else
		{
			cout << "NAM";
		}
	}
}