#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 9;

bool is_compatible_consecutive(int A, int B, int M) {
    for (int a_row = 0; a_row < M; ++a_row) {
        if ((A >> a_row) & 1) {
            for (int b_row = 0; b_row < M; ++b_row) {
                if ((B >> b_row) & 1) {
                    if (abs(a_row - b_row) == 2) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool is_compatible_two_apart(int A, int C, int M) {
    for (int a_row = 0; a_row < M; ++a_row) {
        if ((A >> a_row) & 1) {
            for (int c_row = 0; c_row < M; ++c_row) {
                if ((C >> c_row) & 1) {
                    if (abs(a_row - c_row) == 1) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1, T2> &p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

using Matrix = vector<vector<int>>;

Matrix multiply(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix result(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            if (A[i][k] == 0) continue;
            for (int j = 0; j < n; ++j) {
                result[i][j] = (result[i][j] + static_cast<long long>(A[i][k]) * B[k][j]) % MOD;
            }
        }
    }
    return result;
}

Matrix matrix_pow(Matrix mat, int power) {
    int n = mat.size();
    Matrix result(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        result[i][i] = 1;
    }
    while (power > 0) {
        if (power & 1) {
            result = multiply(result, mat);
        }
        mat = multiply(mat, mat);
        power >>= 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int M, N;
    cin >> M >> N;

    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (N == 1) {
        long long ans = 1;
        for (int i = 0; i < M; ++i) {
            ans = (ans * 2) % MOD;
        }
        cout << ans << endl;
        return 0;
    }

    vector<int> masks;
    for (int i = 0; i < (1 << M); ++i) {
        masks.push_back(i);
    }

    vector<pair<int, int>> valid_pairs;
    for (int A : masks) {
        for (int B : masks) {
            if (is_compatible_consecutive(A, B, M)) {
                valid_pairs.emplace_back(A, B);
            }
        }
    }

    int K = valid_pairs.size();
    if (N == 2) {
        cout << K % MOD << endl;
        return 0;
    }

    unordered_map<pair<int, int>, int, pair_hash> state_index;
    for (int i = 0; i < K; ++i) {
        state_index[valid_pairs[i]] = i;
    }

    Matrix T(K, vector<int>(K, 0));
    for (int i = 0; i < K; ++i) {
        int A = valid_pairs[i].first;
        int B = valid_pairs[i].second;
        for (int C : masks) {
            if (!is_compatible_consecutive(B, C, M)) {
                continue;
            }
            if (!is_compatible_two_apart(A, C, M)) {
                continue;
            }
            pair<int, int> new_state(B, C);
            auto it = state_index.find(new_state);
            if (it != state_index.end()) {
                int j = it->second;
                T[i][j] = (T[i][j] + 1) % MOD;
            }
        }
    }

    Matrix mat_exp = matrix_pow(T, N - 2);

    long long total = 0;
    for (const auto& row : mat_exp) {
        for (int val : row) {
            total = (total + val) % MOD;
        }
    }

    cout << total % MOD << endl;

    return 0;
}