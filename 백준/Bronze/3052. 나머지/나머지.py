from typing import List
import sys

def sol_3052(ls: List[int]) -> int:
    mods = set(map(lambda x: x % 42, ls))
    return len(mods)

if __name__ == "__main__":
    ls = [None] * 10
    for i in range(10):
        ls[i] = int(sys.stdin.readline())
    print(sol_3052(ls))