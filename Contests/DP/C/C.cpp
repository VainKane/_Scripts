#include <bits/stdc++.h>

using namespace std;

short int n;
short int nums[109];
set<short int> s;
short int temp[(int)1e6 + 10];
short int index = 0;
short int pos[10009];

int Search(short int nums[], short int target, short int l, short int r)
{
    int mid;

    while (l <= r)
    {
        mid = (l + r) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return -1;
}

int main()
{
    cin >> n;

    for (short int i = 0; i < n; i++)
    {
        cin >> nums[i];
        s.insert(nums[i]);
    }

    for (short int i = 0; i + 1 < n; i++)
    {
        for (short int j = i + 1; j < n; j++)
        {
            s.insert(nums[i] + nums[j]);
            pos[nums[i] + nums[j]] = j;

            if (Search(temp, nums[i] + nums[j], 0, index) == -1)
            {
                temp[index] = nums[i] + nums[j];
                index++;
            }
        }
    }

    for (short int k = 3; k <= n; k++)
    {
        short int cnt = index;
        index = 0;

        for (short int j = 0; j <= cnt; j++)
        {

            for (short int i = pos[temp[j]] + 1; i < n; i++)
            {
                short int a = pos[temp[j]];
                short int b = temp[j];
                short int c = nums[i];
                if (s.count(b + c) == 0)
                {
                    temp[index] = b + c;
                    index++;
                    s.insert(b + c);
                }
            }
        }
    }

    cout << 0;

    for (short int value : s)
    {
        cout << ' ' << value;
    }



    return 0;
}
