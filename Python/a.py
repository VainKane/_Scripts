class TrieNode:
    def __init__(self):
        self.children = {}
        self.count = 0

class Trie:
    def __init__(self):
        self.root = TrieNode()
        self.BITS = 30  # Vì a[i] ≤ 10^9, nên tối đa 30 bit là đủ

    def insert(self, num):
        node = self.root
        for i in range(self.BITS, -1, -1):
            bit = (num >> i) & 1
            if bit not in node.children:
                node.children[bit] = TrieNode()
            node = node.children[bit]
            node.count += 1

    def count_less_than(self, num, K):
        node = self.root
        count = 0
        for i in range(self.BITS, -1, -1):
            if not node:
                break
            bit_num = (num >> i) & 1
            bit_K = (K >> i) & 1

            if bit_K == 1:
                if bit_num in node.children:
                    count += node.children[bit_num].count
                node = node.children.get(1 - bit_num, None)
            else:
                node = node.children.get(bit_num, None)
        return count

def count_subarrays(n, K, arr):
    trie = Trie()
    trie.insert(0)  # Khởi tạo với prefix = 0
    prefix = 0
    result = 0

    for num in arr:
        prefix ^= num
        result += trie.count_less_than(prefix, K)
        trie.insert(prefix)

    return result

# Đọc input
n, K = map(int, input().split())
arr = list(map(int, input().split()))

# Xuất kết quả
print(count_subarrays(n, K, arr))
