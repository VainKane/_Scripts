def min_difference(n, a):
    total_weight = sum(a)
    target = total_weight // 3
    dp = [[[False] * (target + 1) for _ in range(target + 1)] for _ in range(n + 1)]
    dp[0][0][0] = True

    for i in range(1, n + 1):
        for j in range(target + 1):
            for k in range(target + 1):
                if dp[i - 1][j][k]:
                    dp[i][j][k] = True
                    if j + a[i - 1] <= target:
                        dp[i][j + a[i - 1]][k] = True
                    if k + a[i - 1] <= target:
                        dp[i][j][k + a[i - 1]] = True

    min_diff = float('inf')
    for j in range(target + 1):
        for k in range(target + 1):
            if dp[n][j][k]:
                l = total_weight - j - k
                current_diff = max(j, k, l) - min(j, k, l)
                if current_diff < min_diff:
                    min_diff = current_diff

    return min_diff

n = int(input())
a = [int(i) for i in input().split()]
print(min_difference(n, a))