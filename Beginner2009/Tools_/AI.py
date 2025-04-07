MOD = 10**9 + 7

def multiply(a, b):
    res = [[0] * 32 for _ in range(32)]
    for i in range(32):
        for k in range(32):
            if a[i][k] == 0:
                continue
            for j in range(32):
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD
    return res

def matrix_power(mat, power):
    result = [[0] * 32 for _ in range(32)]
    for i in range(32):
        result[i][i] = 1  # Ma trận đơn vị
    while power > 0:
        if power % 2 == 1:
            result = multiply(result, mat)
        mat = multiply(mat, mat)
        power //= 2
    return result

n = int(input())
if n == 0:
    print(0)
else:
    # Xây dựng ma trận chuyển tiếp
    transition = [[0] * 32 for _ in range(32)]
    odd_digits = {1: 0, 3: 1, 5: 2, 7: 3, 9: 4}
    for i in range(32):
        # Thêm chữ số chẵn (0,2,4,6,8) → 5 cách, không đổi bitmask
        transition[i][i] += 5
        # Thêm chữ số lẻ → flip bit tương ứng
        for d in odd_digits:
            idx = odd_digits[d]
            j = i ^ (1 << idx)
            transition[i][j] += 1
        # Modulo
        for j in range(32):
            transition[i][j] %= MOD

    # Tính transition^(n-1)
    powered = matrix_power(transition, n-1)

    # Vector ban đầu: 4 cách chẵn, 5 cách lẻ (mỗi bit set 1)
    initial = [0] * 32
    initial[0] = 4  # Chữ số chẵn (2,4,6,8)
    for bit in range(5):
        initial[1 << bit] += 1  # Chữ số lẻ 1,3,5,7,9

    # Nhân vector ban đầu với ma trận đã lũy thừa
    result = [0] * 32
    for i in range(32):
        if initial[i] == 0:
            continue
        for j in range(32):
            result[j] = (result[j] + initial[i] * powered[i][j]) % MOD

    # Tổng tất cả các trạng thái đều hợp lệ
    total = sum(result) % MOD
    print(total)