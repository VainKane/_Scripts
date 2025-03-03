#include <bits/stdc++.h>

using namespace std;

short int n;
short int nums[109];
set<short int> s;
short int temp[(int)1e8 + 10];
short int index = 0;
bool pos[10009][109];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (short int i = 0; i < n; i++)
    {
        cin >> nums[i];
        s.insert(nums[i]);
    }

    for (int i = 0; i < 10009; i++)
    {
        for (int j = 0; j < 109; j++)
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
                temp[index] = nums[i] + nums[j];
                s.insert(temp[index]);

                if (!pos[temp[index]][105])
                {
                    pos[temp[index]][i] = true;
                    pos[temp[index]][j] = true;
                    pos[temp[index]][105] = true;
                }
                else
                {
                    for (int r = 0; r < n; r++)
                    {
                        if (pos[temp[index]][r])
                        {
                            if (r == i || r == j)
                            {
                                pos[temp[index]][r] = true;
                            }
                            else
                            {
                                pos[temp[index]][r] = false;
                            }
                        }
                        else
                        {
                            pos[temp[index]][r] = false;
                        }

                    }
                }

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
        bool isCheck = false;
        short int clone[10009];


        for (short int j = 0; j < cnt; j++)
        {
            clone[j] = temp[j];
        }

        for (short int j = 0; j < cnt; j++)
        {
            for (short int i = 0; i < n; i++)
            {
                if (!pos[clone[j]][i])
                {
                    isCheck = true;

                    temp[index] = clone[j] + nums[i];

                    if (!pos[temp[index]][105])
                    {
                        for (int r = 0; r < n; r++)
                        {
                            pos[temp[index]][r] = pos[clone[j]][r];
                        }
                        pos[temp[index]][i] = true;
                        pos[temp[index]][105] = true;
                    }
                    else
                    {
                        for (int r = 0; r < n; r++)
                        {
                            if (pos[temp[index]][r] && pos[clone[j]][r])
                            {
                                pos[temp[index]][r] = true;
                            }
                            else
                            {
                                pos[temp[index]][r] = false;
                            }
                        }

                        pos[temp[index]][i] = true;
                    }

                    if (s.count(clone[j] + nums[i]) == 0)
                    {
                        s.insert(temp[index]);
                        index++;
                    }
                }
            }
        }

        if (!isCheck)
        {
            break;
        }
    }

    cout << 0;

    for (short int value : s)
    {
        if (value != 0)
        {
            cout << ' ' << value;
        }

    }



    return 0;
}
