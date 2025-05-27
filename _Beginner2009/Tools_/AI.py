import sys

def can_transform(x, y):
    if len(y) < len(x):
        return False
    if x == y:
        return True
    current = {y}
    for _ in range(len(y) - len(x)):
        next_level = set()
        for s in current:
            # Check if last character is 'A' and add the truncated string
            if s[-1] == 'A':
                next_level.add(s[:-1])
            # Check if first character is 'B' and add reversed remaining part
            if s[0] == 'B':
                next_level.add(s[1:][::-1])
        current = next_level
        if not current:
            return False
    return x in current

for line in sys.stdin:
    line = line.strip()
    if not line:
        continue
    x, y = line.split()
    print("YES" if can_transform(x, y) else "NO")