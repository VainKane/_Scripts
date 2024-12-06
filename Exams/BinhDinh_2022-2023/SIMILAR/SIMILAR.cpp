#include <bits/stdc++.h>

using namespace std;

int Count(int n)
{
    int count = 0;

    while (n > 0)
    {
        count += n % 10;
        n /= 10;
    }

    return count;
}

int num[60];

int diff = 0;

int l;
int r;

int main()
{
    cin >> l >> r;


    for (int i = 0; i <= 54; i++)
    {
        num[i] = 0;
    }

    for (int i = l; i <= r; i+= 10)
    {
        int value = Count(i);

        for (int j = i; j < i + 10; j++)
        {
            value += 1;

            if (num[value] == 0)
            {
                num[value] = j;
            }
            else
            {
                if (diff < j - num[value])
                {
                    diff = j - num[value];
                }
            }
        }
    }



    cout << diff;
}

