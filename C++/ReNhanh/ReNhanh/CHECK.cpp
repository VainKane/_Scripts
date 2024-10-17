#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int num;
	
	int tram;
	int chuc;
	int dv;

	int hangNghin;
	int hangTram;
	int hangChuc;

	cin >> num;
	hangNghin = num / 1000;
	
	tram = num - hangNghin * 1000;
	hangTram = tram / 100;

	chuc = tram - hangTram * 100;
	hangChuc = chuc / 10;

	dv = chuc - hangChuc * 10;



	if (hangNghin + hangTram == hangChuc + dv)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}