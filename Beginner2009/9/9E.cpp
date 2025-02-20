#include <bits/stdc++.h>

using namespace std;

int n;
int a[7009];

vector<tuple<int, int, int>> res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    
    
    return 0;
}