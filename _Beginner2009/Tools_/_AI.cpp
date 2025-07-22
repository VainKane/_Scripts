#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define name "raspored"

// Fenwick tree (BIT) hỗ trợ cập nhật điểm và truy vấn tổng prefix
struct Fenwick {
    int n; vector<ll> f;
    Fenwick(int n): n(n), f(n+1,0) {}
    // Cập nhật thêm delta tại vị trí i
    void update(int i, ll delta) {
        for(; i <= n; i += i & -i) f[i] += delta;
    }
    // Truy vấn tổng prefix [1..i]
    ll query(int i) {
        ll s = 0;
        for(; i > 0; i -= i & -i) s += f[i];
        return s;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen(name".inp", "r", stdin);
    // freopen(name".out", "w", stdout);

    int subtask, n, q;
    cin >> subtask >> n >> q;
    vector<ll> t(n+1), d(n+1);
    for(int i = 1; i <= n; i++){
        cin >> t[i] >> d[i];
    }
    vector<int> p(q);
    vector<ll> newt(q), newd(q);

    // Gom tất cả giá trị d (ban đầu + cập nhật) để nén tọa độ
    vector<ll> vals;
    vals.reserve(n + q);
    for(int i = 1; i <= n; i++) vals.push_back(d[i]);
    for(int i = 0; i < q; i++){
        cin >> p[i] >> newt[i] >> newd[i];
        vals.push_back(newd[i]);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int m = vals.size();
    
    // Khởi tạo Fenwick trees: bitCnt đếm số lượng, bitSum tính tổng giá trị
    Fenwick bitCnt(m), bitSum(m);
    // Thêm các d ban đầu vào BIT
    for(int i = 1; i <= n; i++){
        int idx = lower_bound(vals.begin(), vals.end(), d[i]) - vals.begin() + 1;
        bitCnt.update(idx, 1);
        bitSum.update(idx, d[i]);
    }
    // Tính tổng t và tổng C ban đầu
    ll sumT = 0;
    for(int i = 1; i <= n; i++) sumT += t[i];
    vector<ll> dvals(n);
    for(int i = 0; i < n; i++) dvals[i] = d[i+1];
    sort(dvals.begin(), dvals.end());
    ll sumC = 0, pref = 0;
    for(int i = 0; i < n; i++){
        pref += dvals[i];
        sumC += pref;
    }
    // In kết quả ngày đầu
    cout << (sumT - sumC);

    // Xử lý từng cập nhật
    for(int i = 0; i < q; i++){
        int person = p[i];
        ll ti_new = newt[i], di_new = newd[i];
        // Cập nhật tổng t
        sumT += (ti_new - t[person]);
        t[person] = ti_new;

        // Xóa giá trị d cũ khỏi BIT
        ll v_old = d[person];
        int idx_old = lower_bound(vals.begin(), vals.end(), v_old) - vals.begin() + 1;
        ll cnt_le_old = bitCnt.query(idx_old);
        ll sum_le_old = bitSum.query(idx_old);
        // Tính delta do xóa (theo công thức đã phân tích)
        ll delta_rem = - sum_le_old - (ll)(n - cnt_le_old) * v_old;
        bitCnt.update(idx_old, -1);
        bitSum.update(idx_old, -v_old);

        // Chèn giá trị d mới vào BIT
        ll v_new = di_new;
        int idx_new = lower_bound(vals.begin(), vals.end(), v_new) - vals.begin() + 1;
        ll cnt_le_new = bitCnt.query(idx_new);
        ll sum_le_new = bitSum.query(idx_new);
        ll delta_ins = sum_le_new + (ll)(n - cnt_le_new) * v_new;
        bitCnt.update(idx_new, 1);
        bitSum.update(idx_new, v_new);

        // Cập nhật tổng C và giá trị d của người đó
        sumC += (delta_rem + delta_ins);
        d[person] = di_new;

        // In kết quả sau mỗi ngày
        cout << " " << (sumT - sumC);
    }
    cout << "\n";
    return 0;
}