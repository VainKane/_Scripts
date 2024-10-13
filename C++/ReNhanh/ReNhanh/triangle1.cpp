#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	int a;
	int b;
	int c;

	string result;

	cin >> a >> b >> c;

	if (abs(b - c) < a && a < b + c)
	{
		result = "YES";
	}
	else
	{
		result = "NO";
	}

	cout << result;
}