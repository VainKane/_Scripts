def compute_sum(n, a, b):
    total = 0
    k = a
    while k <= b:
        q = n // k  # Giá trị của ⌊n/k⌋
        if q == 0:
            break  # Khi q = 0, tất cả k lớn hơn đều sẽ có ⌊n/k⌋ = 0
        
        # Tìm khoảng lớn nhất mà ⌊n/k⌋ vẫn bằng q
        last_k = min(n // q, b)  
        
        # Số lượng k trong khoảng này
        count = last_k - k + 1  
        
        # Cộng vào tổng
        total += count * q  
        
        # Nhảy đến giá trị tiếp theo
        k = last_k + 1  
    
    return total

# Đọc input
n, a, b = map(int, input().split())

# Tính kết quả
result = compute_sum(n, a, b)

# In kết quả
print(result)
