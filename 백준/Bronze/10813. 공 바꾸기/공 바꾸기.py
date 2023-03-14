import sys
from typing import List


if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    ls: List[int] = list(range(n + 1))
    for _ in range(m):
        i, j = map(int, sys.stdin.readline().split())
        ls[i], ls[j] = ls[j], ls[i]

    print(*ls[1:])