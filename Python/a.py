def removeKDigits(S, K):
    stack = []
    for char in S:
        while stack and K > 0 and stack[-1] > char:
            stack.pop()
            K -= 1
        stack.append(char)
    
    # Nếu vẫn còn K ký tự cần xóa, xóa từ cuối ngăn xếp
    if K > 0:
        stack = stack[:-K]
    
    # Loại bỏ các số 0 ở đầu (nếu có)
    result = ''.join(stack).lstrip('0')
    
    return result if result else "0"

# Đọc input
S = input().strip()
K = int(input())

# Tính toán và in ra kết quả
print(removeKDigits(S, K))