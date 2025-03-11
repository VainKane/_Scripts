#include <bits/stdc++.h>

using namespace std;

int const maxLog = 17;
int const N = 1e5 + 10;

int n;

int a[N];
int lg[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    // for (int i = 1; i <= n; i++) cin >> a[i];

    lg[1] = 0;
    for (int i = 2; i <= 1e5; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }

    cout << lg[n];

    return 0;
}