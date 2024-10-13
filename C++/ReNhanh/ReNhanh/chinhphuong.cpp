#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int num;

	cin >> num;

	if ((int)sqrt(num) * (int)sqrt(num) == num)
	{
		cout << "yes";
	}
	else
	{
		cout << "no";
	}

}