#include <bits/stdc++.h>

using namespace std;

bool bit(int i, int mask)
{
    return mask >> i; 
}

int d[100][100];

int main()
{
    // cout << bit(4, 15); 

    memset(d, 0x7f, sizeof d);
    // cout << d[0] << '\n' << (1ll << 31) - 1 << '\n' << (1ll << 63) - 1;
    cout << d[0][0];
}