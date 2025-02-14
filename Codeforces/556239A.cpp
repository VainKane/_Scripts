#include <bits/stdc++.h>

using namespace std;

int Search(string name, string &c)
{
    string can[10]{"CANH", "TAN", "NHAM", "QUY", "GIAP", "AT", "BINH", "DINH", "MAU", "KY"};
    string chi[12]{"THAN", "DAU", "TUAT", "HOI", "TI", "SUU", "DAN", "MAO", "THIN", "TY", "NGO", "MUI"};

    for (int i = 0; i < 10; i++)
    {
        if (can[i] == name) 
        {
            c = "can";
            return i;
        }
    }
    for (int i = 0; i < 12; i++)
    {
        if (chi[i] == name) 
        {
            c = "chi";
            return i;
        }
    }

    return -1;
}



int n;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> s;

    string c;

    int u = Search(s, c); // nam den 

    if (c == "can")
    {
        int v = n % 10; // nam dang xet

        if (u == v)
        {
            cout << n;
            return 0;
        }
        else
        {
            int x = min(abs(v - u), min(10 - v + u, v + 10 - u));
            
            int a = n + x;
            int b = n - x;

            if (b % 10 == u)
            {
                cout << b;
                return 0;
            }
            else
            {
                cout << a;
                return 0;
            }
        }
    }
    else
    {
        int v = n % 12; // nam dang xet

        if (u == v)
        {
            cout << n;
            return 0;
        }
        else
        {
            int x = min(abs(v - u), min(12 - v + u, v + 12 - u));
            
            int a = n + x;
            int b = n - x;

            if (b % 12 == u)
            {
                cout << b;
                return 0;
            }
            else
            {
                cout << a;
                return 0;
            }
        }
    }

    return 0;
}