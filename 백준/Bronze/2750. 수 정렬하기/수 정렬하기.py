from __future__ import annotations
import sys

def sol_2750(num_list: List[int]) -> List[int]:
    num_list.sort()
    return num_list

n = int(sys.stdin.readline())
num_list = []
for i in range(n):
    num_list.append(int(sys.stdin.readline()))
result = sol_2750(num_list)
for i in range(n):
    print(result[i])