#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

struct SegmentTreeNode {
    int l, r;
    SegmentTreeNode *left, *right;
    long long mul, add;
    long long val; // Only for leaves

    SegmentTreeNode(int l_, int r_) : l(l_), r(r_), left(nullptr), right(nullptr), mul(1), add(0), val(0) {}

    bool is_leaf() const {
        return l == r;
    }
};

SegmentTreeNode* build(int l, int r, vector<int>& a) {
    SegmentTreeNode* node = new SegmentTreeNode(l, r);
    if (l == r) {
        node->val = a[l] % MOD;
    } else {
        int mid = (l + r) / 2;
        node->left = build(l, mid, a);
        node->right = build(mid + 1, r, a);
    }
    return node;
}

void propagate(SegmentTreeNode* node) {
    if (!node->left) return;

    // Propagate to left child
    node->left->mul = (node->left->mul * node->mul) % MOD;
    node->left->add = (node->left->add * node->mul + node->add) % MOD;

    // Propagate to right child
    node->right->mul = (node->right->mul * node->mul) % MOD;
    node->right->add = (node->right->add * node->mul + node->add) % MOD;

    // Reset current node's parameters
    node->mul = 1;
    node->add = 0;
}

void multiply_range(SegmentTreeNode* node, int u, int v, int d) {
    if (node->r < u || node->l > v) return;
    if (u <= node->l && node->r <= v) {
        node->mul = (node->mul * d) % MOD;
        node->add = (node->add * d) % MOD;
        return;
    }
    propagate(node);
    multiply_range(node->left, u, v, d);
    multiply_range(node->right, u, v, d);
}

void add_range(SegmentTreeNode* node, int u, int v, int d) {
    if (node->r < u || node->l > v) return;
    if (u <= node->l && node->r <= v) {
        node->add = (node->add + d) % MOD;
        return;
    }
    propagate(node);
    add_range(node->left, u, v, d);
    add_range(node->right, u, v, d);
}

long long query_point(SegmentTreeNode* node, int p) {
    if (node->is_leaf()) {
        return (node->val * node->mul + node->add) % MOD;
    }
    propagate(node);
    if (p <= node->left->r) {
        return query_point(node->left, p);
    } else {
        return query_point(node->right, p);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        a[i] %= MOD;
    }
    SegmentTreeNode* root = build(0, n-1, a);
    int m;
    scanf("%d", &m);
    while (m--) {
        char op[2];
        scanf("%s", op);
        if (op[0] == '+' || op[0] == '*') {
            int u, v, d;
            scanf("%d %d %d", &u, &v, &d);
            u--; v--;
            if (op[0] == '+') {
                add_range(root, u, v, d % MOD);
            } else {
                multiply_range(root, u, v, d % MOD);
            }
        } else {
            int p;
            scanf("%d", &p);
            p--;
            long long res = query_point(root, p);
            printf("%lld\n", res % MOD);
        }
    }
    return 0;
}