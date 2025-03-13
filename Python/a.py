a=[float(i) for i in input().split()]

x=sum(a)/len(a)

print (x)

m=abs(a[0]-x)

n=a[0]

for i in a:

    if abs(i-x)<m:

        n=i
        m = abs(i - x)

print(n)