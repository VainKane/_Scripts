#include <bits/stdc++.h>

void Count(std::string str, int count[10]);


std::string str;
int count[10];

int main()
{
    getline(std::cin, str);

    Count(str, count);

    for (int item : count)
    {
        std::cout << item << ' ';
    }
}

void Count(std::string str, int count[10])
{
    for (int i = 0; i < 10; i++)
    {
        count[i] = 0;
    }
    
    for (char chr : str)
    {
        if (chr >= '0' && chr <= '9');
        {
            count[chr - '0'] += 1;
        }
    }
}