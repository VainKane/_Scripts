#include <bits/stdc++.h>

using namespace std;

short int n;
short int nums[109];
set<short int> s;
short int temp[(int)1e6 + 10];
short int index = 0;
bool pos[10009][109];

int main()
{
    cin >> n;

    for (short int i = 0; i < n; i++)
    {
        cin >> nums[i];
        s.insert(nums[i]);
    }

    for (int i = 0; i < 10001; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            pos[i][j] = false;
        }
    }

    for (short int i = 0; i + 1 < n; i++)
    {
        for (short int j = i + 1; j < n; j++)
        {
            if (s.count(nums[i] + nums[j]) == 0)
            {
                s.insert(nums[i] + nums[j]);
                temp[index] = nums[i] + nums[j];
                pos[nums[i] + nums[j]][i] = true;
                pos[nums[i] + nums[j]][j] = true;
                index++;
            }
        }
    }

//    for (int i = 0; i < index; i++)
//    {
//        cout << temp[i] << ' ' << pos[temp[i]][0] << pos[temp[i]][1] << '\n';
//    }

    for (short int k = 3; k <= n; k++)
    {
        short int cnt = index;
        index = 0;

        short int clone[10009];
        for (short int j = 0; j < cnt; j++)
        {
            clone[j] = temp[j];
        }

        for (short int j = 0; j < cnt; j++)
        {
            for (short int i = 0; i < n; i++)
            {
//                if (pos[clone[j]] != "")
                {
                    if (!pos[clone[j]][i])
                    {
//                        cout << clone[j] << ' ' << pos[clone[j]] << '\n';

                        if (s.count(clone[j] + nums[i]) == 0)
                        {
                            temp[index] = clone[j] + nums[i];

                            for (int r = 0; r < n; r++)
                            {
                                pos[temp[index]][r] = pos[clone[j]][r];
                            }
                            pos[temp[index]][i] = true;

//                            cout << temp[index] << ' ' << pos[temp[index]] << '\n';
                            s.insert(temp[index]);

                            index++;
                        }
                    }
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
