import sys
from collections import defaultdict, Counter

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

    def search_best_word(self, letters):
        letter_count = Counter(letters)
        best_word = "IMPOSSIBLE"
        
        def dfs(node, current_word):
            nonlocal best_word
            
            if node.is_end:
                if (len(current_word) > len(best_word) or 
                    (len(current_word) == len(best_word) and current_word < best_word)):
                    best_word = current_word
            
            for char, child in node.children.items():
                if letter_count[char] > 0:
                    letter_count[char] -= 1
                    dfs(child, current_word + char)
                    letter_count[char] += 1
        
        dfs(self.root, "")
        return best_word

# Đọc input
def main():
    n = int(input().strip())
    trie = Trie()
    
    for _ in range(n):
        trie.insert(input().strip())
    
    t = int(input().strip())
    results = []
    
    for _ in range(t):
        letters = input().strip()
        results.append(trie.search_best_word(letters))
    
    # Xuất kết quả ra màn hình
    print("\n".join(results))

if __name__ == "__main__":
    main()