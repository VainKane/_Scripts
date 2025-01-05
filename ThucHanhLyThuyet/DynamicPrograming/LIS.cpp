#include <bits/stdc++.h>

using namespace std;

int Search(int nums[], int target, int l, int r)
{
    int mid;
    int res = 0;

    while (l <= r)
    {
        mid = (l + r) / 2;

        if (target > nums[mid])
        {
            if (res < nums[mid])
            {
                res = nums[mid];
            }

            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return res;
}

int n;
int nums[1009];
int l[1009];


int res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        l[i] = 1;
    }

    sort(nums, nums + n);

    
}