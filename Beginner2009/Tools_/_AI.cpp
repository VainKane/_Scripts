#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Node {
    int start;
    int end;
    Node* left;
    Node* right;
    int cover;
    int total;
    Node(int s, int e) : start(s), end(e), left(nullptr), right(nullptr), cover(0), total(0) {}
};

struct Event {
    int x;
    bool is_add;
    int y1;
    int y2;
};

Node* build(int l, int r, const vector<int>& ys) {
    Node* node = new Node(ys[l], ys[r]);
    if (l + 1 >= r) {
        return node;
    }
    int mid = (l + r) / 2;
    node->left = build(l, mid, ys);
    node->right = build(mid, r, ys);
    return node;
}

void update(Node* node, int y1, int y2, int val) {
    if (node->end <= y1 || node->start >= y2) {
        return;
    }
    if (y1 <= node->start && node->end <= y2) {
        node->cover += val;
    } else {
        update(node->left, y1, y2, val);
        update(node->right, y1, y2, val);
    }
    if (node->cover > 0) {
        node->total = node->end - node->start;
    } else {
        node->total = 0;
        if (node->left) node->total += node->left->total;
        if (node->right) node->total += node->right->total;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<int> y_set;
    vector<Event> events;

    for (int i = 0; i < n; ++i) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        events.push_back({x1, true, y1, y2});
        events.push_back({x2, false, y1, y2});
        y_set.insert(y1);
        y_set.insert(y2);
    }

    if (y_set.empty()) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> ys(y_set.begin(), y_set.end());
    int m = ys.size();

    Node* root = build(0, m - 1, ys);

    sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        if (a.x != b.x) return a.x < b.x;
        return a.is_add > b.is_add;
    });

    long long total_area = 0;
    int prev_x = -1;

    for (const auto& event : events) {
        int current_x = event.x;
        if (prev_x != -1 && current_x > prev_x) {
            long long delta_x = current_x - prev_x;
            total_area += delta_x * root->total;
        }

        if (event.is_add) {
            update(root, event.y1, event.y2, 1);
        } else {
            update(root, event.y1, event.y2, -1);
        }

        prev_x = current_x;
    }

    cout << total_area << '\n';

    return 0;
}