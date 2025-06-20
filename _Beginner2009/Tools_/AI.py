def solve():
    a, b, c = map(int, input().split())
    
    # Xây dựng xâu B
    B = ""
    for i in range(a + 1):
        B += "0" if i % 2 == 0 else "1"
        
    # Xây dựng xâu C
    C = ""
    for i in range(b + 1):
        C += "0" if i % 2 == 0 else "1"
        
    # Xây dựng xâu A
    A = ""
    for i in range(c + 1):
        A += "0" if i % 2 == 0 else "1"
        
    print(A)
    print(B)
    print(C)
    
solve()