def solve():
    with open("MICOST.INP", "r") as f:
        n, c = map(int, f.readline().split())
        h = [int(f.readline()) for _ in range(n)]

    hmax = 1000
    INF = float('inf')

    # F[i][x] = chi phí thấp nhất để chỉnh sửa tòa nhà thứ i có chiều cao x
    F_prev = [0] * (hmax + 1)
    for x in range(hmax + 1):
        if x < h[0]:
            F_prev[x] = INF
        else:
            F_prev[x] = (x - h[0]) ** 2

    for i in range(1, n):
        Low = [INF] * (hmax + 2)
        High = [INF] * (hmax + 2)

        # Tính mảng Low và High từ F_prev
        for x in range(1, hmax + 1):
            Low[x] = min(Low[x - 1], F_prev[x] - c * x)
        for x in range(hmax, -1, -1):
            High[x] = min(High[x + 1], F_prev[x] + c * x)

        F_curr = [INF] * (hmax + 1)
        for x in range(h[i], hmax + 1):  # Chỉ xét chiều cao >= h[i]
            option1 = Low[x] + c * x
            option2 = High[x] - c * x
            F_curr[x] = min(option1, option2) + (x - h[i]) ** 2

        F_prev = F_curr  # Chuẩn bị cho vòng lặp tiếp theo

    result = min(F_prev)
    with open("MICOST.OUT", "w") as f:
        f.write(str(result))


# Gọi hàm giải
solve()
