import sys
from collections import defaultdict

class DSU:
    def __init__(self, n):
        self.parent = list(range(n + 1))
        self.size = [1] * (n + 1)
    
    def find(self, x):
        while self.parent[x] != x:
            self.parent[x] = self.parent[self.parent[x]]
            x = self.parent[x]
        return x
    
    def union(self, x, y):
        xroot = self.find(x)
        yroot = self.find(y)
        if xroot == yroot:
            return False
        if self.size[xroot] < self.size[yroot]:
            xroot, yroot = yroot, xroot
        self.parent[yroot] = xroot
        self.size[xroot] += self.size[yroot]
        return True

def main():
    input = sys.stdin.read
    data = input().split()
    idx = 0
    n = int(data[idx])
    m = int(data[idx + 1])
    idx += 2
    p = list(map(int, data[idx:idx + n]))
    idx += n
    edges = []
    for _ in range(m):
        u = int(data[idx])
        v = int(data[idx + 1])
        edges.append((u, v))
        idx += 2
    
    # Sắp xếp các đỉnh theo trọng số giảm dần
    sorted_nodes = sorted(range(1, n + 1), key=lambda x: -p[x - 1])
    
    dsu = DSU(n)
    res = [-1] * (n + 1)
    max_size = defaultdict(int)
    
    for node in sorted_nodes:
        for neighbor in edges:
            if neighbor[0] == node or neighbor[1] == node:
                dsu.union(node, neighbor[0] if neighbor[1] == node else neighbor[1])
        root = dsu.find(node)
        size = dsu.size[root]
        if res[size] == -1:
            res[size] = p[node - 1]
        else:
            res[size] = max(res[size], p[node - 1])
    
    # Điền các giá trị còn thiếu
    for k in range(n - 1, 0, -1):
        if res[k] == -1:
            res[k] = res[k + 1]
    
    print(' '.join(map(str, res[1:])))

if __name__ == "__main__":
    main()