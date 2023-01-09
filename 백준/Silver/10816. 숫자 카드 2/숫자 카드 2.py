from __future__ import annotations
import sys

def sol_10816(cards: List[int], query: List[int]) -> List[int]:
    cards_hash = dict()
    result = []
    for card in cards:
        if card in cards_hash.keys():
            cards_hash[card] += 1
        else:
            cards_hash[card] = 1
    for card in query:
        result.append(0 if card not in cards_hash.keys() else cards_hash[card])
    return result

n = int(sys.stdin.readline())
cards = list(map(int, sys.stdin.readline().split()))
m = int(sys.stdin.readline())
query = list(map(int, sys.stdin.readline().split()))
print(*sol_10816(cards, query))