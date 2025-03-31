MOD = 10**9 + 7

class SegmentTreeNode:
    def __init__(self, l, r):
        self.l = l
        self.r = r
        self.left = None
        self.right = None
        self.mul = 1
        self.add = 0
        self.val = 0  # Only for leaves

    def is_leaf(self):
        return self.l == self.r

def build(l, r, a):
    node = SegmentTreeNode(l, r)
    if l == r:
        node.val = a[l] % MOD
    else:
        mid = (l + r) // 2
        node.left = build(l, mid, a)
        node.right = build(mid + 1, r, a)
    return node

def propagate(node):
    if not node.left:
        return
    # Propagate to left child
    left = node.left
    left.mul = (left.mul * node.mul) % MOD
    left.add = (left.add * node.mul + node.add) % MOD
    # Propagate to right child
    right = node.right
    right.mul = (right.mul * node.mul) % MOD
    right.add = (right.add * node.mul + node.add) % MOD
    # Reset current node's parameters
    node.mul = 1
    node.add = 0

def multiply_range(node, l, r, d):
    if node.r < l or node.l > r:
        return
    if l <= node.l and node.r <= r:
        node.mul = (node.mul * d) % MOD
        node.add = (node.add * d) % MOD
        return
    propagate(node)
    multiply_range(node.left, l, r, d)
    multiply_range(node.right, l, r, d)

def add_range(node, l, r, d):
    if node.r < l or node.l > r:
        return
    if l <= node.l and node.r <= r:
        node.add = (node.add + d) % MOD
        return
    propagate(node)
    add_range(node.left, l, r, d)
    add_range(node.right, l, r, d)

def query_point(node, p):
    if node.is_leaf():
        return (node.val * node.mul + node.add) % MOD
    propagate(node)
    mid = (node.l + node.r) // 2
    if p <= mid:
        return query_point(node.left, p)
    else:
        return query_point(node.right, p)

def main():
    import sys
    input = sys.stdin.read().split()
    ptr = 0
    n = int(input[ptr])
    ptr += 1
    a = list(map(int, input[ptr:ptr + n]))
    ptr += n
    a = [x % MOD for x in a]
    root = build(0, n-1, a)
    m = int(input[ptr])
    ptr += 1
    for _ in range(m):
        cmd = input[ptr]
        ptr += 1
        if cmd in ('+', '*'):
            u = int(input[ptr]) - 1
            ptr += 1
            v = int(input[ptr]) - 1
            ptr += 1
            d = int(input[ptr])
            ptr += 1
            if cmd == '+':
                add_range(root, u, v, d)
            else:
                multiply_range(root, u, v, d % MOD)  # Ensure d is modulo MOD for multiplication
        else:
            p = int(input[ptr]) - 1
            ptr += 1
            res = query_point(root, p)
            print(res % MOD)

if __name__ == "__main__":
    main()