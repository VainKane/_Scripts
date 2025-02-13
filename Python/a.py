MOD = 10**9 + 7

def power_mod(a, b, mod=MOD):
    """Tính a^b % mod bằng lũy thừa nhị phân"""
    res = 1
    while b:
        if b % 2:
            res = res * a % mod
        a = a * a % mod
        b //= 2
    return res

def precompute_factorials(limit, mod=MOD):
    """Tiền xử lý giai thừa và nghịch đảo giai thừa"""
    fact = [1] * (limit + 1)
    invFact = [1] * (limit + 1)
    
    for i in range(2, limit + 1):
        fact[i] = fact[i-1] * i % mod
    
    invFact[limit] = power_mod(fact[limit], mod-2, mod)  # invFact[n] = fact[n]^(MOD-2) % MOD
    
    for i in range(limit - 1, 0, -1):
        invFact[i] = invFact[i + 1] * (i + 1) % mod
    
    return fact, invFact

def comb(n, k, fact, invFact, mod=MOD):
    """Tính C(n, k) % mod"""
    if k < 0 or k > n:
        return 0
    return fact[n] * invFact[k] % mod * invFact[n-k] % mod

# Đọc input
T = int(input())
queries = [tuple(map(int, input().split())) for _ in range(T)]

# Tìm giá trị lớn nhất của m+n để tiền xử lý
max_val = max(m + n for m, n in queries)

# Tiền xử lý giai thừa và nghịch đảo giai thừa
fact, invFact = precompute_factorials(max_val)

# Tính kết quả cho từng test case
for m, n in queries:
    print(comb(m + n, m, fact, invFact))
