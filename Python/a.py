def find_permutation(n, p):
    result = [0] * n
    available = list(range(1, n + 1))  # Danh sách các số từ 1 đến n
    
    for i in range(n - 1, -1, -1):
        result[i] = available.pop(p[i])  # Lấy phần tử có chỉ số p[i]
    
    print(*result)

# Đọc input
n = int(input())
p = list(map(int, input().split()))

# Gọi hàm giải
find_permutation(n, p)
