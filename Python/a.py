import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    m = int(data[0])
    n = int(data[1])
    c = []
    index = 2
    for i in range(m):
        c.append(list(map(int, data[index:index + m])))
        index += m
    
    k = m // n  # Số chương trình con mỗi máy
    best_cost = float('inf')
    assignment = [-1] * m  # Gán mỗi chương trình con vào máy nào
    
    def backtrack(prog_idx, current_cost):
        nonlocal best_cost
        if prog_idx == m:
            # Đã gán xong tất cả chương trình con
            best_cost = min(best_cost, current_cost)
            return
        
        for machine in range(n):
            # Kiểm tra xem máy này đã đủ k chương trình con chưa
            if assignment.count(machine) >= k:
                continue
            
            # Tính chi phí tăng thêm khi gán chương trình con này vào máy
            added_cost = 0
            for other_prog in range(prog_idx):
                if assignment[other_prog] != machine:
                    added_cost += c[prog_idx][other_prog]
            
            # Nếu chi phí hiện tại + chi phí tăng thêm >= best_cost, bỏ qua
            if current_cost + added_cost >= best_cost:
                continue
            
            # Gán chương trình con này vào máy
            assignment[prog_idx] = machine
            backtrack(prog_idx + 1, current_cost + added_cost)
            assignment[prog_idx] = -1  # Quay lui
    
    backtrack(0, 0)
    print(best_cost)

if __name__ == "__main__":
    main()