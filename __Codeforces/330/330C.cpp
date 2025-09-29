#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define sz(v) ((int)v.size())
#define F first
#define S second

int const N = 109;

int n;
char a[N][N];

void Print()
{
    cout << -1;
    exit(0);
}

bool PureRow()
{

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) FOR(j, 1, n) cin >> a[i][j];

    Try();

    FOR(i, 1, n)

    return 0;
}