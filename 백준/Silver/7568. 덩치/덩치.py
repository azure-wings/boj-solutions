from typing import List, Tuple
import sys

def sol_7568(ls: List[Tuple[int, int]]) -> List[int]:
    l = len(ls)
    counts = [None] * l
    for i in range(l):
        larger = [ p for p in ls if p[0] > ls[i][0] and p[1] > ls[i][1] ]
        counts[i] = len(larger) + 1
    return counts

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    ls = [None] * n
    for i in range(n):
        ls[i] = tuple(map(int, sys.stdin.readline().split()))
    print(*sol_7568(ls))