from typing import List
import sys

def binary_search(lo: int, hi: int, n: int) -> int:
    if lo > hi:
        return hi
    mid = (lo + hi) // 2
    if sum([(c // mid) for c in cables]) >= n:
        return binary_search(mid+1, hi, n)
    else:
        return binary_search(lo, mid-1, n)

def sol_1654(n: int, cables: List[int]) -> int:
    return binary_search(1, max(cables), n)

if __name__ == "__main__":
    k, n = map(int, sys.stdin.readline().split())
    cables = [None] * k
    for i in range(k):
        cables[i] = int(sys.stdin.readline())
    print(sol_1654(n, cables))