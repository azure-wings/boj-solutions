from typing import List
from itertools import combinations
import sys

def sol_2798(cards: List[int], target: int) -> int:
    combs = combinations(cards, r=3)
    sums  = filter(lambda x: x <= target, [ sum(c) for c in combs ])
    return max(list(sums))

if __name__ == "__main__":
    _, m = map(int, sys.stdin.readline().split())
    cards = list(map(int, sys.stdin.readline().split()))
    print(sol_2798(cards, m))