#include <bits/stdc++.h>

using namespace std;

bool bit(int i, int mask)
{
    return mask >> i; 
}

long long d[100];

int main()
{
    // cout << bit(4, 15); 

    memset(d, 0x3f, sizeof d);
    // cout << (1ll << 63) - 1 << '\n' << d[0];

    cout << bitset<64>(-23);

}