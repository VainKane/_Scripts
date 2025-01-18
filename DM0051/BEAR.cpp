#include <bits/stdc++.h>

using namespace std;

long long black;
long long brown;
long long grey;

long long maxVal;

string res;

int main()
{
    cin >> black >> brown >> grey;

    maxVal = black;
    res = "BLACK";

    if (maxVal < brown) 
    {
        maxVal = brown;
        res = "BROWN";
    }
    if (maxVal < grey)
    {
        maxVal = grey;
        res = "GREY";
    } 

    cout << res;

    return 0;
}