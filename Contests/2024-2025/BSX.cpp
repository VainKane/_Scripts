#include <bits/stdc++.h>

using namespace std;

bool Check1(string str)
{
    bool con1 = false;
    bool con2 = false;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            con1 = true;        
        }
        if (str[i] >= '0' && str[i] <= '9')
        {
            con2 = true;
        }
    }

    if (con1 && con2)
    {
        return true;
    }
    return false;
}

bool Check2(string str)
{
    int con = 0;

    if (str[0] >= 'A' && str[0] <= 'Z')
    {
        con++;
    }
    if (str[str.length() - 1] >= '0' && str[str.length() - 1] <= '9')
    {
        con++;
    }

    if (con == 2)
    {
        return true;
    }
    return false;
}

bool Check3(string str)
{
    for (int i = 0; i + 1 < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i + 1] >= 'A' && str[i] <= 'Z' && str[i + 1] <= 'Z')
        {
            return false;
        }
        if (str[i] >= '0' && str[i + 1] >= '0' && str[i] <= '9' && str[i + 1] <= '9')
        {
            return false;
        }
    }

    return true;
}

string str;

int t;

int main()
{
    cin >> t;
    cin.ignore();

    while (t--)
    {
        getline(cin, str);
        int res = Check1(str) + Check2(str) + Check3(str);

        if (res == 3)
        {
            cout << "PERFECT\n";
        }
        else if (res == 2)
        {
            cout << "VALID\n";
        }
        else
        {
            cout << "INVALID\n";
        }
    }
}