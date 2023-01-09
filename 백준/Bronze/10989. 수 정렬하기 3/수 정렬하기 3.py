from __future__ import annotations
import sys

def sol_10989(n: int) -> None:
    count = [0]*10000
    for i in range(n):
        count[int(sys.stdin.readline())-1] += 1
    for i in range(10000):
        if count[i] == 0:
            pass
        else:
            for j in range(count[i]):
                print(i+1)

n = int(sys.stdin.readline())
sol_10989(n)