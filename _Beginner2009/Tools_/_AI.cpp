#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; ++i)
typedef long long       ll;
const ll INF = (ll)-4e18;
const int N  = 5005;          // n ≤ 5000

int n, k;
ll L, R, SG;
ll a[N];
int lowIdx[N], highIdx[N];
ll w[N], dpPrev[N], dpCur[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    /* ---------- Đọc dữ liệu ---------- */
    cin >> n >> k;
    cin >> L >> R;
    cin >> SG;
    FOR(i, 1, n) cin >> a[i];

    /* ---------- Hệ số trọng số ---------- */
    FOR(t, 1, k) w[t] = 2LL * t - k - 1;     // w_t = 2t - k - 1

    /* ---------- Tiền xử lý cửa sổ ---------- */
    FOR(i, 1, n) {
        int l = lower_bound(a + 1, a + i, a[i] - R) - a;          // a[p] ≥ a[i]-R
        int r = upper_bound(a + 1, a + i, a[i] - L) - a - 1;      // a[p] ≤ a[i]-L
        lowIdx[i]  = l;
        highIdx[i] = r;                                           // (l ≤ r) ⇒ cửa sổ tồn tại
    }

    /* ---------- Khởi tạo cho t = 1 ---------- */
    FOR(i, 1, n) dpPrev[i] = INF;
    FOR(i, 1, n)
        if (a[i] >= L && a[i] <= R) dpPrev[i] = w[1] * a[i];

    /* ---------- Quy hoạch động cho t = 2..k ---------- */
    deque<int> dq;
    FOR(t, 2, k) {
        dq.clear();
        int left = 1, right = 0;                 // [left, right] là cửa sổ hiện tại
        FOR(i, 1, n) {
            /* mở rộng right tới highIdx[i] */
            while (right < highIdx[i]) {
                ++right;
                if (dpPrev[right] == INF) continue;          // giá trị không hợp lệ
                while (!dq.empty() && dpPrev[dq.back()] <= dpPrev[right])
                    dq.pop_back();
                dq.push_back(right);
            }
            /* thu hẹp left lên lowIdx[i] */
            while (left < lowIdx[i]) {
                if (!dq.empty() && dq.front() == left) dq.pop_front();
                ++left;
            }

            dpCur[i] = dq.empty() ? INF
                                  : dpPrev[dq.front()] + w[t] * a[i];
        }
        /* chuyển sang bước kế */
        FOR(i, 1, n) dpPrev[i] = dpCur[i];
    }

    /* ---------- Lấy kết quả cuối ---------- */
    ll best = INF;
    FOR(i, 1, n)
        if (SG - a[i] >= L && SG - a[i] <= R)
            best = max(best, dpPrev[i]);

    cout << best * 2 << '\n';       // nhân 2 vì ∑Ti = 2·∑|xi-xj|
    return 0;
}
