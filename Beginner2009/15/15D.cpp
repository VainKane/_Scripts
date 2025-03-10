#include <bits/stdc++.h>

using namespace std;

#define bit(i, x) ((x >> i) & 1)

int const N = 1e5;
int const maxBit = 30;

int n;
int k;
int a[N];

int child[N * 30 + 2][32];

int cnt = 0;

void Add(int &x)
{
    int u = 0;
    for (int i = maxBit; i >= 0; i--)
    {
        int k = bit(i, x);
        if (!child[u][k]) child[u][k] = ++cnt;
        u = child[u][k];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];



    return 0;
}