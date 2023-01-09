from __future__ import annotations
from functools import reduce
import sys

def sol_1026(A: List[int], B: List[int]) -> int:
    A.sort()
    B.sort(reverse=True)
    return reduce(lambda acc, x: acc + x[0]*x[1], list(zip(A, B)), 0)
    
n = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
B = list(map(int, sys.stdin.readline().split()))
print(sol_1026(A, B))