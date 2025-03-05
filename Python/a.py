def min_insertions_to_palindrome(n, s):
    s_reverse = s[::-1]  # Chuỗi đảo ngược

    # Khởi tạo bảng DP
    dp = [[0] * (n + 1) for _ in range(n + 1)]

    # Tính LCS giữa s và s_reverse
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if s[i - 1] == s_reverse[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    # Số ký tự cần chèn vào
    return n - dp[n][n]


# Đọc input
n = int(input().strip())
s = input().strip()

# Xuất kết quả
print(min_insertions_to_palindrome(n, s))
