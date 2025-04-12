#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define fi first
#define se second

int const N = 1e5 + 5;

int n;

int a[N];
int bit[N];
vector<int> b;

int trace[N]; // To store the trace for LIS reconstruction
int pos[N];   // To store the position of the maximum value in BIT

void Update(int idx, int val, int k)
{
    while (idx <= n)
    {
        if (bit[idx] < val)
        {
            bit[idx] = val;
            pos[idx] = k; // Store the position for trace-back
        }
        idx += idx & -idx;
    }
}

int GetMax(int idx, int &lastPos)
{
    int res = 0;
    lastPos = 0;

    while (idx)
    {
        if (bit[idx] > res)
        {
            res = bit[idx];
            lastPos = pos[idx]; // Get the position of the maximum value
        }
        idx -= idx & -idx;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b.push_back(a[i]);
    }

    // Coordinate compression
    sort(all(b));
    b.erase(unique(all(b)), b.end());

    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(all(b), a[i]) - b.begin() + 1;
    }

    int res = 0, lastIdx = 0;

    for (int i = 1; i <= n; i++)
    {
        int prevPos;
        int maxVal = GetMax(a[i] - 1, prevPos) + 1; // Get the max value and its position
        Update(a[i], maxVal, i); // Update BIT and store the trace
        trace[i] = prevPos;      // Store the trace for reconstruction

        if (maxVal > res)
        {
            res = maxVal;
            lastIdx = i; // Track the last index of the LIS
        }
    }

    // Reconstruct the LIS
    vector<int> lis;
    while (lastIdx)
    {
        lis.push_back(b[a[lastIdx] - 1]); // Convert back to original value
        lastIdx = trace[lastIdx];
    }

    reverse(all(lis));

    // Output the LIS length and sequence
    cout << lis.size() << '\n';
    for (auto val : lis) cout << val << ' ';

    return 0;
}