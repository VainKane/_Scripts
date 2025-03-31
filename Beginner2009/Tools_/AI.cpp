#include <bits/stdc++.h>

using namespace std;

int const N = 20;

int n;
int a[N], b[N];
int posA[N], posB[N];
long long require[N];
long long dp[1 << N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        posA[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
        posB[b[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (posA[i] < posA[j] && posB[i] < posB[j]) {
                require[j] |= (1LL << i);
            }
        }
    }

    dp[0] = 1;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (dp[mask] == 0) continue;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) continue;
            if ((mask & require[i]) == require[i]) {
                dp[mask | (1 << i)] += dp[mask];
            }
        }
    }

    cout << dp[(1 << n) - 1] << endl;
    return 0;
}