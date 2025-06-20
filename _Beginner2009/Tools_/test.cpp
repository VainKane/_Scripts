#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

long long GCD(long long a, long long b)
{
    long long r = a % b;
    if (!r) return b;

    while (b)
    {
        cnt++;
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int a[23] = {0, 1, 2, 3};

int main()
{
    // GCD(1e18, 4352345234231234);
    // cout << cnt;

    // int n; cin >> n;

    // for (int i = 1; i <= n; i++) a[i] = i;
    
    // do
    // {
    //     for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    //     cout << '\n';
    // } while (next_permutation(a + 1, a + n + 1));

    // string s = "abcde";
    // s.resize(s.size() - 1);
    // cout << s;

    priority_queue<int> pq;
    pq.push(2);
    pq.push(2);
    pq.push(2);

    // cout << pq.size();

    cout << (long long)10e18;
}