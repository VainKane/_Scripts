#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

int n;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) cout << a[i];
    cout << '\n';



    return 0;
}
