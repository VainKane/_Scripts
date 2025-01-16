#include <bits/stdc++.h>

using namespace std;

int Count(int nums[], int target, int l, int r)
{
    int mid;
    int res = 0;

    while (l <= r)
    {
        if (nums[mid] <= target)
        {
            if (nums[mid] == target)
            {
                res++;
            }

            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }

    return res;
}

int n;
int q;
int nums[(int)1e5 + 10];

int main()
{
    cin >> n >> q;

    for (int i = 0; i < n; i++) cin >> nums[i];


    while (q--)
    {
        int x;
        int l;
        int r;

        cin >> l >> r >> x;

        sort(nums, nums + n);


        cout << Count(nums, x, l, r) << '\n';
    }

    return 0;
}
