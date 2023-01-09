from __future__ import annotations
import sys

def sol_1920(A: List[int], B: List[int]) -> List[int]:
    A_set = set(A)
    result = []
    for num in B:
        result.append(1 if num in A_set else 0)
    return result

n = int(sys.stdin.readline())
A = map(int, sys.stdin.readline().split())
m = int(sys.stdin.readline())
B = map(int, sys.stdin.readline().split())
result = sol_1920(A, B)
for i in range(len(result)):
    print(result[i])