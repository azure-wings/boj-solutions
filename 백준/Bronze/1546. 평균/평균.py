from typing import List
import sys

def sol_1546(ls: List[int]) -> float:
    max_score = max(ls)
    return (sum(ls)*(100.0/max_score)) / len(ls)

if __name__ == "__main__":
    _ = int(sys.stdin.readline())
    ls = list(map(int, sys.stdin.readline().split()))
    print(sol_1546(ls))