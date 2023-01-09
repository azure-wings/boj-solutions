from __future__ import annotations
import sys

def sol_10815(cards: List[int], query: List[int]) -> List[int]:
    result = [0] * len(query)
    set_cards = set(cards)
    
    for i, card in enumerate(query):
        if card in set_cards:
            result[i] = 1
    
    return result

n = int(sys.stdin.readline())
cards = list(map(int, sys.stdin.readline().split()))
m = int(sys.stdin.readline())
query = list(map(int, sys.stdin.readline().split()))
print(*sol_10815(cards, query))