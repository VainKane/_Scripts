#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "ghim"
typedef long long ll;

int const N = 1e5 + 5;

int n;
ll Umin = -4e18, Umax = 4e18, Vmin = -4e18, Vmax = 4e18;

ll toU(ll x, ll y) { return x + y; }
ll toV(ll x, ll y) { return x - y; }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        ll x[4], y[4], u[4], v[4];
        FOR(j, 0, 3) cin >> x[j] >> y[j];
        FOR(j, 0, 3)
        {
            u[j] = toU(x[j], y[j]);
            v[j] = toV(x[j], y[j]);
        }

        ll umin = *min_element(u, u + 4) + 1;
        ll umax = *max_element(u, u + 4) - 1;
        ll vmin = *min_element(v, v + 4) + 1;
        ll vmax = *max_element(v, v + 4) - 1;

        Umin = max(Umin, umin);
        Umax = min(Umax, umax);
        Vmin = max(Vmin, vmin);
        Vmax = min(Vmax, vmax);
    }

    if (Umin > Umax || Vmin > Vmax)
    {
        cout << 0;
        return 0;
    }

    ll res = 0;

    // Tổng số điểm (u,v) nguyên trong hình chữ nhật mở
    ll cntU = Umax - Umin + 1;
    ll cntV = Vmax - Vmin + 1;

    // Trong đó (u + v) phải chẵn để (x, y) là nguyên
    // Tức là số cặp (u,v) sao cho u+v chẵn
    // Với mỗi cặp chẵn-chẵn hoặc lẻ-lẻ
    // Nếu cntU chẵn, cntV chẵn:
    //     số điểm chẵn-chẵn = cntU/2 * cntV/2
    //     số điểm lẻ-lẻ = (cntU/2) * (cntV/2)
    // Nếu cntU lẻ, cntV lẻ:
    //     số điểm chẵn-chẵn = (cntU+1)/2 * (cntV+1)/2
    //     số điểm lẻ-lẻ = (cntU-1)/2 * (cntV-1)/2
    // Tổng = tổng các điểm có u + v chẵn

    ll evenU = (cntU + 1) / 2;
    ll oddU = cntU / 2;
    ll evenV = (cntV + 1) / 2;
    ll oddV = cntV / 2;

    res = evenU * evenV + oddU * oddV;

    cout << res << '\n';
}
