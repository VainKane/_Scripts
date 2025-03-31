n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

posA = [0] * (n + 1)
for idx, x in enumerate(A):
    posA[x] = idx

posB = [0] * (n + 1)
for idx, x in enumerate(B):
    posB[x] = idx

# Initialize must_before matrix
must_before = [[False] * (n + 1) for _ in range(n + 1)]
for i in range(1, n + 1):
    for j in range(1, n + 1):
        if i != j and posA[i] < posA[j] and posB[i] < posB[j]:
            must_before[i][j] = True

# Precompute required masks for each element
required = [0] * (n + 1)
for j in range(1, n + 1):
    mask = 0
    for i in range(1, n + 1):
        if must_before[i][j]:
            mask |= 1 << (i - 1)
    required[j] = mask

# Initialize DP
size = 1 << n
dp = [0] * size
dp[0] = 1

for mask in range(size):
    if dp[mask] == 0:
        continue
    for j in range(1, n + 1):
        bit = 1 << (j - 1)
        if not (mask & bit):
            if (mask & required[j]) == required[j]:
                new_mask = mask | bit
                dp[new_mask] += dp[mask]

print(dp[-1])