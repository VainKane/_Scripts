def can_fit(n, w, h, words, k):
    cur_width = 0
    cur_height = 0
    max_height_in_row = 0
    lines_needed = 1
    
    for ai, bi in words:
        word_width = ai * k
        word_height = bi * k

        if word_width > w or word_height > h:
            return False  # Nếu một từ riêng lẻ lớn hơn kích thước cửa sổ thì k không hợp lệ
        
        if cur_width + word_width <= w:
            cur_width += word_width
            max_height_in_row = max(max_height_in_row, word_height)
        else:
            # Xuống dòng mới
            cur_width = word_width
            max_height_in_row = word_height
            lines_needed += 1
        
        if lines_needed * max_height_in_row > h:
            return False

    return True


def find_max_k(n, w, h, words):
    left, right = 0, min(w / max(ai for ai, _ in words), h / max(bi for _, bi in words))
    eps = 1e-6
    
    while right - left > eps:
        mid = (left + right) / 2
        if can_fit(n, w, h, words, mid):
            left = mid
        else:
            right = mid

    return left


# Đọc dữ liệu đầu vào
n, w, h = map(int, input().split())
words = [tuple(map(int, input().split())) for _ in range(n)]

# Tìm k lớn nhất
result = find_max_k(n, w, h, words)

# In kết quả với độ chính xác 10^-6
print(f"{result:.6f}")
