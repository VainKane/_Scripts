#include <bits/stdc++.h>

using namespace std;

int const N = 1e2 + 10;

int n;

int nums[N];
int a[N];
int b[N];

int ia = 0;
int ib = 0;

int k;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums, nums + n);

    a[0] = nums[0];
    b[0] = nums[1];

    for (int i = 2; i < n; i++)
    {
        if (nums[i] > a[ia] && nums[i] <= b[ib])
        {
            ia++;
            a[ia] = nums[i];
        }
        else if (nums[i] > b[ib] && nums[i] <= a[ia])
        {
            ib++;
            b[ib] = nums[i];
        }
        else 
        {
            if (ia <= ib && nums[i] > a[ia])
            {
                ia++;
                a[ia] = nums[i];
            }
            else if (nums[i] > b[ib])
            {
                ib++;
                b[ib] = nums[i];
            }
        }
    }

    // for (int i = 0; i < n; i++) cout << nums[i] << ' ';
    // cout << '\n';
    // for (int i = 0; i <= ia; i++) cout << a[i] << ' ';
    // cout << '\n'; 
    // for (int i = 0; i <= ib; i++) cout << b[i] << ' ';
    // cout << '\n';

    if (a[ia] > b[ib]) ib++;
    else if (b[ib] > a[ia]) ia++;

    if (ia < ib) k = ia;
    else k = ib;

    cout << 2 * k + 1;      

    return 0;
}