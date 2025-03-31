#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int x = 1;
    int y = 0;
};

int const N = 1e5 + 5;
int const MOD = 1e9 + 7;

int n;
int a[N];
Node t[4 * N];

void Update(int v, int l, int r, int left, int right, int x, int y)
{
    if (l > right || r < left) return;
    if (left <= l && right >= r)
    {
        
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    return 0;
}