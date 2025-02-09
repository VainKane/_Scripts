



// CPP program to find
// sum of given series
#include <bits/stdc++.h>
using namespace std;
 
// function to find sum of series
long long int sum(long long int n)
{
    long long int root = sqrt(n);
    long long int ans = 0;
 
    for (int i = 1; i <= root; i++) 
        ans += n / i;
     
    ans = 2 * ans - (root * root);
    return ans;
}
 
// driver code
int main()
{
    long long int n = 35;
    cout << sum(n);
    return 0;
}