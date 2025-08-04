#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int n, k;
vector<int> adj[N];

vector<int> nodes;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, k) 
    {
        int p; cin >> p;
        nodes.push_back(p);
    }

    return 0;
}