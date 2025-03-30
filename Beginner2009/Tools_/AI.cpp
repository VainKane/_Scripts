#include <bits/stdc++.h>

using namespace std;

int const N = 15;

int n;
int a[N + 5];
int dp[(1 << N)][N + 5];
int cnt[(1 << N)][N + 5]; // Mảng đếm số cách đạt giá trị dp

int bit(int i, long long mask) {
    return (mask >> i) & 1;
}

long long TurnOff(int i, long long mask) {
    return mask & (~(1 << i));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (cin >> n) {
        if (!n) exit(0);
        memset(dp, 0, sizeof dp);
        memset(cnt, 0, sizeof cnt);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            dp[1 << i][i] = a[i];
            cnt[1 << i][i] = 1; // Ban đầu có 1 cách tạo trạng thái này
        }

        for (int mask = 0; mask < (1 << n); mask++) {
            for (int i = 0; i < n; i++) {
                if (!bit(i, mask)) continue;

                for (int j = 0; j < n; j++) {
                    if (i == j || !bit(j, mask)) continue;

                    int prev_mask = TurnOff(i, mask);
                    int new_value = dp[prev_mask][j] + abs(a[i] - a[j]);

                    if (new_value > dp[mask][i]) {
                        dp[mask][i] = new_value;
                        cnt[mask][i] = cnt[prev_mask][j]; // Ghi đè số cách
                    } else if (new_value == dp[mask][i]) {
                        cnt[mask][i] += cnt[prev_mask][j]; // Cộng dồn số cách
                    }
                }
            }
        }

        int res = 0, ways = 0;

        for (int i = 0; i < n; i++) {
            int perimeter = dp[(1 << n) - 1][i] + a[i] + 2 * n;
            if (perimeter > res) {
                res = perimeter;
                ways = cnt[(1 << n) - 1][i];
            } else if (perimeter == res) {
                ways += cnt[(1 << n) - 1][i];
            }
        }

        cout << res << ' ' << ways << '\n';
    }

    return 0;
}
