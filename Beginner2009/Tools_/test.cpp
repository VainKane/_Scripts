#include <bits/stdc++.h>

using namespace std;

bool bit(int i, int mask)
{
    return mask >> i; 
}

int main()
{
    cout << bit(4, 15); 
}