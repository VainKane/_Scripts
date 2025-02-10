#include <bits/stdc++.h>

using namespace std;

int n;

int a[(int)1e5 + 10];
int pre[(int)1e5 + 10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    pre[0] = a[0];

    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    

    return 0;
}