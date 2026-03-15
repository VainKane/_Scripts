#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

long long solve() {
    int n, k, p, m;
    cin >> n >> k >> p >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Adjust p to 0-indexed
    p--; 
    int win_val = a[p];

    // If the win condition is already in the first k
    if (p < k) {
        // Minimum cost to bring it back to the window after it moves to the end (n-1)
        // To move from n-1 to k-1, we need to play (n-1) - (k-1) = n - k cards.
        // These cards will be the cheapest among the first k at each step.
        
        // Let's simplify: 
        // 1. Play win_val (cost: win_val). Now it's at index n-1.
        // 2. To get it back to index k-1, we need to play (n-k) cards.
        // The cheapest card in the first k will always be available.
        
        int min_other = 2e9;
        for(int i = 0; i < k; i++) {
            if (i != p) min_other = min(min_other, a[i]);
        }
        // Special case: if n=1, min_other doesn't exist, but n-k would be 0.
        
        if (m < win_val) return 0;
        
        // First play
        long long count = 1;
        long long current_m = m - win_val;

        // Subsequent plays: cost is win_val + (n-k) * (cheapest available)
        // After win-condition is played, it's at the end. We must shift n-k times.
        // The cards available to shift are the ones currently in the first k.
        // The win-condition is NOT in the first k during this shifting.
        
        // We need the cheapest card among the CURRENT first k.
        // Since we can pick ANY of the first k, we just pick the global minimum 
        // of the cards that can ever be in that window.
        int global_min = 2e9;
        for(int x : a) global_min = min(global_min, x);

        long long cycle_cost = (long long)(n - k) * global_min + win_val;
        count += current_m / cycle_cost;
        
        return count;
    } else {
        // Win condition is at p >= k.
        // Must move it p - (k-1) times to get it to index k-1.
        int global_min = 2e9;
        for(int i = 0; i < k; i++) global_min = min(global_min, a[i]);
        
        long long initial_move_cost = (long long)(p - k + 1) * global_min;
        if (m < initial_move_cost + win_val) return 0;
        
        long long current_m = m - (initial_move_cost + win_val);
        long long count = 1;
        
        // Now it's the same as the first case: win condition is at the end.
        int absolute_min = 2e9;
        for(int x : a) absolute_min = min(absolute_min, x);
        
        long long cycle_cost = (long long)(n - k) * absolute_min + win_val;
        count += current_m / cycle_cost;
        
        return count;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}