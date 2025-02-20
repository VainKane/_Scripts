def can_fit(words, w, h, k):
    lines = 0
    current_width = 0
    max_height = 0
    
    for ai, bi in words:
        scaled_width = ai * k
        scaled_height = bi * k
        
        if current_width + scaled_width > w:  # Không đủ chỗ, xuống dòng mới
            lines += max_height  # Cộng chiều cao dòng trước vào tổng chiều cao
            if lines + scaled_height > h:  # Nếu quá chiều cao cửa sổ, không thể fit
                return False
            current_width = scaled_width
            max_height = scaled_height
        else:
            current_width += scaled_width
            max_height = max(max_height, scaled_height)
    
    lines += max_height  # Cộng dòng cuối
    return lines <= h

def max_scaling_factor(w, h, words):
    left, right = 0, min(w / max(a for a, _ in words), h / max(b for _, b in words))
    
    while right - left > 1e-6:  # Dừng khi sai số đủ nhỏ
        mid = (left + right) / 2
        if can_fit(words, w, h, mid):
            left = mid
        else:
            right = mid
    
    return left

# Đọc dữ liệu vào
n, w, h = map(int, input().split())
words = [tuple(map(int, input().split())) for _ in range(n)]

# Tìm k lớn nhất
result = max_scaling_factor(w, h, words)
print(f"{result:.6f}")