from collections import deque

def max_total_service(n, k, L, R, D, A):
    # Khởi tạo bảng DP với giá trị nhỏ để tìm max
    dp = [[-float('inf')] * (k + 1) for _ in range(n + 1)]
    dp[0][0] = 0  # Không chọn trạm nào thì giá trị phục vụ = 0

    # Duyệt số lượng màn hình LED được chọn (từ 1 đến k)
    for j in range(1, k + 1):
        dq = deque()  # Deque dùng để tối ưu việc tìm giá trị lớn nhất
        
        for i in range(1, n + 1):  
            # Loại bỏ các p không hợp lệ (quá xa so với a_i)
            while dq and A[i - 1] - A[dq[0] - 1] > R:
                dq.popleft()

            # Chọn giá trị tốt nhất từ deque
            if dq:
                p = dq[0]
                dp[i][j] = dp[p][j-1] + sum(abs(A[i - 1] - A[x - 1]) for x in range(1, n + 1))

            # Loại bỏ các phần tử kém hiệu quả từ deque
            while dq and dp[dq[-1]][j-1] < dp[i][j-1]:
                dq.pop()

            # Thêm i vào deque
            dq.append(i)

    # Kết quả là giá trị lớn nhất khi chọn đúng k màn hình
    return max(dp[i][k] for i in range(1, n + 1))

# Ví dụ sử dụng
n, k = 5, 3
L, R = 2, 5
D = 10
A = [1, 3, 6, 7, 9]

print(max_total_service(n, k, L, R, D, A))