#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int K = *max_element(a.begin(), a.end());
    sort(a.begin(), a.end());
    int left = 0, right = n - 1;
    int cnt = 0;
    while (left <= right) {
        if (a[right] == 4) {
            cnt++;
            right--;
        } else {
            if (a[left] + a[right] <= 4) {
                cnt++;
                left++;
                right--;
            } else {
                cnt++;
                right--;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}