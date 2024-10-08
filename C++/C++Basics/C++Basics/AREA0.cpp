#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	double a;
	double b;

	cin >> a >> b;

	cout << fixed << setprecision(2);

	cout << a * b - (3.14f * pow((a / 2), 2));
}