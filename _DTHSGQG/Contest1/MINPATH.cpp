#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define mp make_pair

int const N = 2e5 + 5;

struct Data
{
    long long sum;
    int ma, mi;

    bool operator < (Data const other) const
    {
        return sum - ma + mi > other.sum - other.ma + other.mi;
    }
};

void Dijkstra()
{
    priority_queue<pair<Data, int>> pq;
    pq.push(mp(Data{0, 1, (int)1e9}, 1));

    while (!pq.empty())
    {
        int u = pq.top().F;
        Data du = pq.top().S;
    }
}