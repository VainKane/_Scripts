#include <bits/stdc++.h>

using namespace std;

string str;
string res = "";

int main()
{
    getline(cin, str);
 
    for (char key : str)
    {
        if (key == 'o') res += 'o';
        else if (key == 'w') res += 'w';
        else if (key == 'm') res += 'm';
        else if (key == 'b') res += 'd';
        else if (key == 'd') res += 'b';
        else if (key == 'p') res += 'q';
        else if (key == 'q') res += 'p';
    }

    for (int i = res.length() - 1; i >= 0; i--) cout << res[i];

    return 0;
}