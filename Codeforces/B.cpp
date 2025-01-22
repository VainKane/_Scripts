#include <bits/stdc++.h>

using namespace std;

int n;
int nums[(int)1e5 + 10];
int t;
int l;
int r;

int ia;
int ib;

long long sum1;
long long sum2;
long long sum;

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n >> l >> r;
        l--; r--;
        sum = sum1 = sum2 = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> nums[i]; 

            if (i >= l && i <= r)
            {
                sum += nums[i];
            }
        }

        sort(nums, nums + l);
        sort(nums + l, nums + r + 1);
        if (r + 1 < n) sort(nums + r + 1, nums + n);

        ia = r;
        ib = 0;

        while (nums[ib] < nums[ia] && ib < l && ia >= l)
        {
            sum1 += nums[ib];
            
            ia--;
            ib++;
        }
        sum1 = sum - sum1;

        ia = r;
        ib = r + 1;

        while (nums[ib] < nums[ia] && ib < n && ia >= l)
        {
            sum2 += nums[ib];
            
            ia--;
            ib++;
        }
        sum2 = sum - sum2;

        cout << min(sum1, sum2) << '\n';
    }

    return 0;
}