MOD = 1000000007

class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False

class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end = True

    def search_prefix(self, text, start, dp):
        node = self.root
        for i in range(start, len(text)):
            if text[i] not in node.children:
                return
            node = node.children[text[i]]
            if node.is_end:
                dp[i + 1] = (dp[i + 1] + dp[start]) % MOD

def count_ways(n, S, X):
    trie = Trie()
    for word in S:
        trie.insert(word)
    
    dp = [0] * (len(X) + 1)
    dp[0] = 1
    
    for i in range(len(X)):
        if dp[i] > 0:
            trie.search_prefix(X, i, dp)

    return dp[len(X)]

# Đọc input
n = int(input().strip())
S = [input().strip() for _ in range(n)]
X = input().strip()

# Xuất kết quả
print(count_ways(n, S, X))
