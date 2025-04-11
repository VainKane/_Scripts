#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>
#include <complex>

#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define REP(i,a) for(int i = 0; i < a; ++i)
#define MP make_pair
#define PB push_back

using namespace std;

int n, a[60111], bit[60111];

#define _(x) ((x) & (-(x)))

inline void update(int k) {
    while (k <= 60000) {
        bit[k]++;
        k += _(k);
    }
}

inline int get(int x) {
    int res = 0;
    while (x > 0) {
        res += bit[x];
        x -= _(x);
    }
    return res;
}

int main() {
    scanf("%d", &n);
    FOR(i,1,n) scanf("%d", &a[i]);
    int res = 0;
    FORD(i,n,1) {
        res += get(a[i]-1);
        update(a[i]);
    }
    cout << res;
    return 0;
}
