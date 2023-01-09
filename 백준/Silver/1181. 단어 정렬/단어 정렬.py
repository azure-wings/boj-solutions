from __future__ import annotations
import sys

def sol_1181(words: Set[str]) -> List[str]:
    words = sorted(list(words), key=lambda x: (len(x), x))
    return words

n = int(sys.stdin.readline())
words = []
for i in range(n):
    words.append(sys.stdin.readline().rstrip())
words = sol_1181(set(words))
for word in words:
    print(word)