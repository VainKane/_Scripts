#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void Check(int num, int x, int y, char &resultOut);

unsigned int a;
unsigned int b;
unsigned int c;

unsigned int x;
unsigned int y;

char aCheck;
char bCheck;
char cCheck;

int trueCase = (int)'x' + (int)'y';

string result = "KHONG";
long long sum;


int main()
{
	cin >> a >> b >> c >> x >> y;

	Check(a, x, y, aCheck);
	Check(b, x, y, bCheck);
	Check(c, x, y, cCheck);

	if (aCheck + bCheck == trueCase)
	{
		result = "CO";
	}
	else if (bCheck + cCheck == trueCase)
	{
		result = "CO";
	}
	else if (cCheck + aCheck == trueCase)
	{
		result = "CO";
	}
	else
	{
		result = "KHONG";
	}

	cout << result;
}


void Check(int num, int x, int y, char &resultOut)
{
	if (num <= x)
	{
		resultOut = 'x';
	}
	else if (num <= y)
	{
		resultOut = 'y';
	}
	else
	{
		resultOut = '0';
	}
}