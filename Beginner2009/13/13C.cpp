#include <bits/stdc++.h>

using namespace std;

int n;
int a[(int)2e5 + 10];
int l[(int)2e5 + 10];
int r[(int)2e5 + 10];

stack<int> st;

int res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[st.top()] < a[i])
        {
            r[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    st = stack<int>();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && a[st.top()] < a[i])
        {
            l[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    // for (int i = 0; i < n; i++) cout << l[i] << ' ';
    // cout << '\n';
    // for (int i = 0; i < n; i++) cout << r[i] << ' ';
    // cout << '\n';

    for (int i = 0; i < n; i++)
    {
        int a = i - l[i];
        int b = r[i] - i;

        if (l[i] == -1) a = 1;
        if (r[i] == -1) b = 1;

        if (l[i] != -1 || r[i] != -1) res += a * b;
    }

    cout << res;

    return 0;
}