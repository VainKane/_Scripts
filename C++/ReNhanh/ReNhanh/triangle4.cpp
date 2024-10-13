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

	if (a == b && b == c)
	{
		result = "YES";
	}
	else
	{
		result = "NO";
	}

	cout << result;
}
