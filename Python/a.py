a = [int(i) for i in input().split()]

x = (int)(input())
k = (int)(input())

k -= 1

b = a[::k]
c = a[k::]

print(b + [x] + c)