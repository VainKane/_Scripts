#include <bits/stdc++.h>

using namespace std;

int const M = 1e6 + 10;

int n;
pair<int, int> a[M];
int b[M];

pair<int, int> res;

int p[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i].first;
        a[i].second = i;
        b[i] = a[i].first;
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);

    

    return 0;    
}