from typing import List
import sys
sys.setrecursionlimit(10**5)

def binary_search(lo: int, hi: int, m: int) -> int:
    if lo > hi:
        return hi
    mid = (lo + hi) // 2
    if sum([max(0, t-mid) for t in trees]) >= m:
        return binary_search(mid+1, hi, m)
    else:
        return binary_search(lo, mid-1, m)

def sol_1654(m: int, trees: List[int]) -> int:
    return binary_search(0, max(trees), m)

if __name__ == "__main__":
    _, m = map(int, sys.stdin.readline().split())
    trees = list(map(int, sys.stdin.readline().split()))
    print(sol_1654(m, trees))