#include <bits/stdc++.h>
using namespace std;

#define name "JEWELRY"
#define all(v) v.begin(), v.end()

const int N = 1e5 + 5;

int n, m, y;
int a[N];
int s[N][10];

long long res = 0;

vector<int> ring_indices; // lưu chỉ số đá gắn vào nhẫn
vector<int> comb;

// Tính tổng độ lộng lẫy nhẫn với các viên đá đã chọn
long long calc_ring_beauty(const vector<int>& stones) {
    vector<int> perm = comb; // chỉ số nhẫn 1..m
    long long best = 0;

    do {
        long long sum = 0;
        for (int i = 0; i < m; i++) {
            sum += s[stones[i]][perm[i]];
        }
        best = max(best, sum);
    } while (next_permutation(all(perm)));

    return best;
}

// Tạo tổ hợp chọn k phần tử từ tập indices, lưu kết quả vào all_combs
void generate_combinations(int start, int k, vector<int>& indices, vector<vector<int>>& all_combs, vector<int>& curr) {
    if ((int)curr.size() == k) {
        all_combs.push_back(curr);
        return;
    }
    for (int i = start; i < (int)indices.size(); i++) {
        curr.push_back(indices[i]);
        generate_combinations(i + 1, k, indices, all_combs, curr);
        curr.pop_back();
    }
}

void Sub1() {
    // Tạo danh sách chỉ số 1..n
    vector<int> indices(n);
    iota(all(indices), 1);

    // Tạo mảnh ghép permutation cho nhẫn
    comb.resize(m);
    iota(all(comb), 1);

    vector<vector<int>> ring_combs;
    vector<int> tmp;

    // Chọn m viên đá để gắn vào nhẫn
    generate_combinations(0, m, indices, ring_combs, tmp);

    for (auto& ring : ring_combs) {
        // Đánh dấu viên đã chọn cho nhẫn
        vector<bool> used(n + 1, false);
        for (int x : ring) used[x] = true;

        // Các viên chưa dùng, dùng cho vòng cổ
        vector<int> rest;
        for (int i = 1; i <= n; i++) {
            if (!used[i]) rest.push_back(i);
        }

        // Chọn y viên cho vòng cổ
        vector<vector<int>> necklace_combs;
        tmp.clear();
        generate_combinations(0, y, rest, necklace_combs, tmp);

        for (auto& necklace : necklace_combs) {
            long long total = 0;
            for (int x : necklace) total += a[x];

            total += calc_ring_beauty(ring);

            res = max(res, total);
        }
    }

    cout << res;
}
