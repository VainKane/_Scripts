import sys

def process_shopping(n, m, prices, customers):
    # Tạo mảng Prefix Sum
    prefix = [0] * (n + 1)
    for i in range(1, n + 1):
        prefix[i] = prefix[i - 1] + prices[i - 1]
    
    results = []
    for t, l, r in customers:
        l -= 1  # Chuyển về chỉ mục 0-based
        r -= 1
        
        # Nếu tổng giá từ l đến r lớn hơn tiền của khách -> duyệt từng mặt hàng
        total_cost = prefix[r + 1] - prefix[l]
        if total_cost <= t:
            t -= total_cost  # Trừ hết số tiền có thể mua
        else:
            for i in range(l, r + 1):
                if t >= prices[i]:
                    t -= (t // prices[i]) * prices[i]
        results.append(t)
    
    return results

# Đọc input
n, m = map(int, sys.stdin.readline().split())
prices = list(map(int, sys.stdin.readline().split()))
customers = [tuple(map(int, sys.stdin.readline().split())) for _ in range(m)]

# Xử lý và in kết quả
output = process_shopping(n, m, prices, customers)
print("\n".join(map(str, output)))
