#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;

int M, N, D, K;
char grid[MAX][MAX];
int sum[MAX][MAX]; // mảng tổng siêu thị

int main() {
    // freopen("KHUDANCU.INP", "r", stdin);
    // freopen("KHUDANCU.OUT", "w", stdout);

    cin >> M >> N >> D >> K;
    for (int i = 1; i <= M; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> grid[i][j];

    // Tạo prefix sum: đếm số siêu thị 'M' từ (1,1) đến (i,j)
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            if (grid[i][j] == 'M')
                sum[i][j]++;
        }
    }

    int ans = 0;
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (grid[i][j] != 'P') continue;

            int x1 = max(1, i - D), y1 = max(1, j - D);
            int x2 = min(M, i + D), y2 = min(N, j + D);

            int countM = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];

            if (countM == K)
                ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}
