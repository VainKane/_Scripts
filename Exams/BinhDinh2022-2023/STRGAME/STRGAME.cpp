#include <bits/stdc++.h>

using namespace std;

int n;
int k;

string str;

int chr[30];

bool isCase1 = false;

int sum = 0;

int main()
{
    cin >> n >> k;
    cin.ignore();

    getline(cin, str);

    for (int i = 0; i < 26; i++)
    {
        chr[i] = 0;
    }

    for (int i = 0; i < str.length(); i++)
    {
        chr[str[i] - 'a'] += 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (chr[i] >= k)
        {
            chr[i] -= (k - 1);
            isCase1 = true;
        }
    }


    if (isCase1 == true)
    {
       for (int i = 0; i < 26; i++)
        {
            if (chr[i] > 0)
            {
                for (int j = 0; j < chr[i]; j++)
                {
                    cout << (char)('a' + i);
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            if (sum < k)
            {
                sum += chr[i];
            }
            else
            {
                cout << (char)('a' + i);
                i = 99;
            }
        }
    }

}
