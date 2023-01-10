from typing import List
import sys

def sol_10807(ls: List[int], n: int) -> int:
    return ls.count(n)

if __name__ == "__main__":
    _ = sys.stdin.readline()
    ls = list(map(int, sys.stdin.readline().split()))
    n = int(sys.stdin.readline())
    print(sol_10807(ls, n))