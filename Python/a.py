def find_max_non_redundant_coalition(n, seats):
    total_seats = sum(seats)
    majority = (total_seats // 2) + 1  # Số ghế cần thiết để quá bán
    
    # DP lưu tổng số ghế lớn nhất có thể đạt được với tập hợp đảng
    dp = [-1] * (total_seats + 1)
    dp[0] = 0  # Khởi tạo trạng thái cơ bản
    
    # Truy vết backtracking
    from_index = [-1] * (total_seats + 1)
    used = [-1] * (total_seats + 1)
    
    for i in range(n):
        a = seats[i]
        for j in range(total_seats, a - 1, -1):
            if dp[j - a] != -1 and dp[j] < dp[j - a] + a:
                dp[j] = dp[j - a] + a
                from_index[j] = j - a
                used[j] = i
    
    # Tìm giá trị lớn nhất không dư
    best_sum = -1
    for s in range(majority, total_seats + 1):
        if dp[s] >= majority:
            best_sum = s
    
    # Tái tạo tập hợp liên minh
    coalition = set()
    while best_sum > 0:
        coalition.add(used[best_sum] + 1)
        best_sum = from_index[best_sum]
    
    # Xuất kết quả
    print(len(coalition))
    print(" ".join(map(str, sorted(coalition))))
    
# Đọc input
n = int(input().strip())
seats = list(map(int, input().strip().split()))
find_max_non_redundant_coalition(n, seats)
