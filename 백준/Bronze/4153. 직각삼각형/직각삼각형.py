from typing import List
from itertools import combinations
import sys

def sol_4153(sides: List[int]) -> bool:
    squared = set([ s**2 for s in sides ])
    two_sum = [ sum(s) for s in combinations(squared, r=2) if sum(s) in squared ]
    return True if two_sum else False

if __name__ == "__main__":
    right, wrong = "right", "wrong"
    while True:
        sides = list(map(int, sys.stdin.readline().split()))
        if sides != [0, 0, 0]:
            print(f"{right if sol_4153(sides) else wrong}")
        else:
            break