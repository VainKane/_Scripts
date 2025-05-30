#include <bits/stdc++.h>

using namespace std;

#define name "lcs"

int a, b, c;    

string A = "";
string B = "";
string C = "";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> a >> b >> c;

    A += string(c, '1');
    B += string(c, '1');

    B += string(a, '0');
    C += string(a, '0');

    C += string(b, '1');
    A += string(b, '1');

    cout << A << '\n' << B << '\n' << C;

    return 0;
}