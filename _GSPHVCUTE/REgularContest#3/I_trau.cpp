#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/

struct Edge {
    int from, to;

    Edge(int _from = 0, int _to = 0) {
        from = _from; to = _to;
    }

    int other(int x) const {
        assert(from == x || to == x);
        return from ^ to ^ x;
    }

    int setDirCost(int src) const {
        assert(from == src || to == src);
        return src != from;
    }
};

#define MAX   3030
int numNode;
vector<int> adj[MAX];
Edge edges[MAX];
int result, allParToChildCost, revCost[MAX], bestRevCost[MAX];

void updateTopTwo(int &first, int &second, int cur) {
    if (cur < first) {
        second = first; first = cur;
    } else minimize(second, cur);
}

void loadTree(void) {
    cin >> numNode;
    FOR(i, 1, numNode) adj[i].clear();

    FOR(i, 1, numNode - 1) {
        int u, v; cin >> u >> v; swap(u, v);
        edges[i] = Edge(u, v);
        adj[u].push_back(i);
        adj[v].push_back(i);
    }

    allParToChildCost = 0;
    result = MAX;
    memset(revCost, 0, (numNode + 1) * sizeof (int));
    memset(bestRevCost, 0, (numNode + 1) * sizeof (int));
}

void dfs(int u, int par) {
    bestRevCost[u] = revCost[u];

    for (int id : adj[u]) {
        int v = edges[id].other(u);
        if (v == par) continue;

        allParToChildCost += edges[id].setDirCost(u);
        revCost[v] = revCost[u] + edges[id].setDirCost(v) - edges[id].setDirCost(u);

        dfs(v, u);
        minimize(bestRevCost[u], bestRevCost[v]);
    }
}

void tryRoot(int root) {
    allParToChildCost = 0;
    revCost[root] = 0;
    dfs(root, -1);

    minimize(result, allParToChildCost);

    int first = MAX, second = MAX;
    for (int id : adj[root]) {
        int v = edges[id].other(root);
        updateTopTwo(first, second, bestRevCost[v]);
    }

    if (adj[root].size() > 1)
    {
        int tmp = allParToChildCost + first + second;
        if (tmp < result)
        {
            result = tmp;
            cout << allParToChildCost << ' ' << first << ' ' << second << ' ' << root << '\n';
        }
    }
}

void process(void) {
    result = MAX;
    FOR(root, 1, numNode) tryRoot(root);
    cout << result << "\n";
}

int main(void) {
// #ifdef ONLINE_JUDGE
    freopen("traffic.inp", "r", stdin);
    freopen("traffic.ans", "w", stdout);
// #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int numTest; cin >> numTest;
    REP(faker, numTest) {
        loadTree();
        process();
    }
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/
