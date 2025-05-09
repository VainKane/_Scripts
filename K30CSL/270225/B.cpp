#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 5;

int n;
int a[N];
int cnt[N];
int cntDiv[N];

int ma = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        cnt[a[i]]++;        
    }

    for (int i = 2; i <= 1e6; i++)
    {
        for (int j = i; j <= 1e6; j += i)
        {
            cntDiv[i] += cnt[j];
        }
    }

    for (int i = 1; i <= 1e6; i++)
    {
        if (cntDiv[i] >= 2) ma = max(ma, i);
    }

    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] % ma == 0)
        {
            if (k) 
            {
                cout << k << ' ' << i;
                exit(0);
            }
            else k = i;
        }
    }


    return 0;    
}