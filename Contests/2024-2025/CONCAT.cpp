#include <bits/stdc++.h>

using namespace std;

int Reverse(int n)
{
    int res = 0;

    while (n)
    {
        res *= 10;
        res += n % 10;
        n /= 10;
    }

    return res;
}

long long CONCAT(int a, int b)
{
    long long res = a;
    int rb = Reverse(b);

    while (rb)
    {
        res *= 10;
        res += rb % 10;
        rb /= 10; 
    }

    if (b % 10 == 0)
    {
        res *= 10;
    }

    return res;
}

int n;
long long l;
long long r;

int nums[(int)1e5 + 10];

int res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> l >> r;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            long long x = CONCAT(nums[i], nums[j]);
            if (x >= l && x <= r)
            {
                cout << nums[i] << ' ' << nums[j] << '\n';
                res++;
            }
            
        }
    }

    cout << res;

    return 0;
}