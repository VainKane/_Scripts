#include <iostream>

using namespace std;

int n;

int main()
{
	cin >> n;

	if (n % 2 == 0)
	{
		cout << n / 2 << " " << n / 2;
	}
	else
	{
		cout << n / 2 << " " << n / 2 + 1;
	}
}
