#include <bits/stdc++.h>

using namespace std;

int Count(int n)
{
    int count = 1;
    int soMu = 0;

    if (n == 1)
    {
        return 1;
    }

    for (int i = 2; i <= sqrt(n); i++)
    {
        while (n % i == 0)
        {
            soMu += 1;
            n /= i;
        }

        count *= (soMu + 1);
        soMu = 0;
    }

    if (n != 1)
    {
        count *= 2;
    }

    return count;
}

int n;
int nums[102];

int count1 = 0;

int main()
{
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        nums[i] = Count(value);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((nums[i] + nums[j]) % 7 == 0)
            {
                count1 += 1;
            }
        }
    }

    cout << count1;
}