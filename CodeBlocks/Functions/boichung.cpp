#include <bits/stdc++.h>

void CMFind(int m, int n);

int m;
int n;

int main()
{
	std::cin >> m >> n;

	CMFind(m, n);
}

void CMFind(int m, int n)
{
	int firstCM;


	for (int i = std::max(m, n); i <= m * n; i += std::max(m, n))
	{
		if (i % std::min(m, n) == 0)
		{
			firstCM = i;
			break;
		}
	}

	std::cout << firstCM;

	firstCM += std::max(m, n);

	for (int i = firstCM; i <= m * n; i += std::max(m, n))
	{
		if (i % std::min(m, n) == 0)
		{
			std::cout << ' ' << i;
		}
	}
	
}