#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int a[4], b[4];
int x, y, z;

int s = 0;

void BFS()
{
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    FOR(i, 1, 3) cin >> a[i], s += a[i];
    FOR(i, 1, 3) cin >> b[i];
    cin >> x >> y >> z;

    return 0;
}