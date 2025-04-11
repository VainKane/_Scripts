#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n;
vector<int> a, compressed;
int bit[MAXN];         // BIT lưu độ dài LIS
int bit_pos[MAXN];     // BIT lưu chỉ số tương ứng với dp max
int dp[MAXN], trace[MAXN];

// Nén tọa độ
int getCompressedIndex(int x) {
    return lower_bound(compressed.begin(), compressed.end(), x) - compressed.begin() + 1;
}

// Cập nhật BIT: lưu độ dài LIS và vị trí tương ứng
void update(int idx, int val, int pos) {
    while (idx < MAXN) {
        if (bit[idx] < val) {
            bit[idx] = val;
            bit_pos[idx] = pos;
        }
        idx += idx & -idx;
    }
}

// Truy vấn BIT: lấy độ dài max và vị trí tương ứng trong đoạn [1..idx]
pair<int, int> query(int idx) {
    int res = 0, pos = -1;
    while (idx > 0) {
        if (bit[idx] > res) {
            res = bit[idx];
            pos = bit_pos[idx];
        }
        idx -= idx & -idx;
    }
    return {res, pos};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    a.resize(n);
    vector<int> original_a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        original_a[i] = a[i];
    }

    // Nén tọa độ
    compressed = a;
    sort(compressed.begin(), compressed.end());
    compressed.erase(unique(compressed.begin(), compressed.end()), compressed.end());

    // DP + BIT
    int max_len = 0, last_idx = -1;
    for (int i = 0; i < n; ++i) {
        int cidx = getCompressedIndex(a[i]);
        auto [prev_len, prev_pos] = query(cidx - 1);
        dp[i] = prev_len + 1;
        trace[i] = prev_pos;

        if (dp[i] > max_len) {
            max_len = dp[i];
            last_idx = i;
        }

        update(cidx, dp[i], i);
    }

    // Truy vết dãy con
    vector<int> lis;
    while (last_idx != -1) {
        lis.push_back(original_a[last_idx]);
        last_idx = trace[last_idx];
    }
    reverse(lis.begin(), lis.end());

    // In kết quả
    cout << lis.size() << '\n';
    for (int x : lis) cout << x << ' ';
    cout << '\n';

    return 0;
}
