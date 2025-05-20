import sys
from collections import deque

def solve():
    input = sys.stdin.read().split()
    ptr = 0
    N, M, K = map(int, input[ptr:ptr+3])
    ptr +=3
    
    good = list(map(int, input[ptr:ptr+M]))
    ptr +=M
    beautiful = list(map(int, input[ptr:ptr+K]))
    ptr +=K
    
    adj = [[] for _ in range(N+1)]
    for i in range(1, N+1):
        parts = list(map(int, input[ptr:ptr+1+int(input[ptr])]))
        ptr += len(parts)
        di = parts[0]
        neighbors = parts[1:]
        adj[i] = neighbors
    
    # BFS from 1 to compute distances
    dist = [-1]*(N+1)
    q = deque()
    dist[1] = 0
    q.append(1)
    
    while q:
        u = q.popleft()
        for v in adj[u]:
            if dist[v] == -1:
                dist[v] = dist[u] + 1
                q.append(v)
    
    # Find minimal distance in good nodes
    min_good = float('inf')
    found_good = False
    for node in good:
        if dist[node] != -1:
            found_good = True
            if dist[node] < min_good:
                min_good = dist[node]
    
    # Find minimal distance in beautiful nodes
    min_beautiful = float('inf')
    found_beautiful = False
    for node in beautiful:
        if dist[node] != -1:
            found_beautiful = True
            if dist[node] < min_beautiful:
                min_beautiful = dist[node]
    
    if not found_good or not found_beautiful:
        print("impossible")
    else:
        print(min_good + min_beautiful)

solve()