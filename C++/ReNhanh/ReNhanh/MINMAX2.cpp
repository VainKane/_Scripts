#include <iostream>

using namespace std;

int a;
int b;

int main()
{
	cin >> a >> b;

	if (a <= b)
	{
		cout << a << " " << b;
	}
	else
	{
		cout << b << " " << a;
	}
}