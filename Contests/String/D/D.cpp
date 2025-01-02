#include <bits/stdc++.h>

using namespace std;

string str;


int n;

int res = 1;

bool s[(int)1e4][(int)1e4];


int main()
{

     getline(cin, str);

     n = str.length();

     for (int i = 0; i < n; i++)
     {
         s[i][i] = true;
     }

     for (int i = 0; i < n; i++)
     {
         for (int j = 1; j < n; j++)
         {
             if (j - i == 1)
             {
                 if (str[i] == str[j])
                 {
                     s[i][j] = true;
                 }
             }
             else
             {
                 if (str[i] == str[j] && s[i + 1][j - 1])
                 {
                     s[i][j] = true;

                     if (j - i + 1 > res)
                     {
                         res = j - i + 1;
                     }
                 }
             }
         }
     }

     cout << res;

    return 0;
}
