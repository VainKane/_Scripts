import sys

def min_segment_sum(n, l, r, a):
    l -= 1  # Convert to 0-based index
    r -= 1
    
    segment = a[l:r+1]  # Extract segment
    outside = a[:l] + a[r+1:]  # Elements outside the segment
    
    segment.sort(reverse=True)  # Sort segment in descending order
    outside.sort()  # Sort outside elements in ascending order
    
    # Try to replace large elements in segment with smaller elements from outside
    k = min(len(segment), len(outside))
    for i in range(k):
        if outside[i] < segment[i]:
            segment[i] = outside[i]
        else:
            break
    
    return sum(segment)

def main():
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    t = int(data[index])  # Number of test cases
    index += 1
    
    results = []
    for _ in range(t):
        n, l, r = map(int, data[index:index+3])
        index += 3
        a = list(map(int, data[index:index+n]))
        index += n
        
        results.append(str(min_segment_sum(n, l, r, a)))
    
    sys.stdout.write("\n".join(results) + "\n")

if __name__ == "__main__":
    main()
