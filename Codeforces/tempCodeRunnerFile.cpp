#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;

    sort(a.begin(), a.end()); // Sorting helps process numbers in order

    set<int> secondBag;
    
    for (int x : a) {
        while (secondBag.count(x)) x++; // Increment until we find a unique value
        secondBag.insert(x);
    }

    // If we were able to make a distinct second bag of size n, print YES
    cout << (secondBag.size() == n / 2 ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
