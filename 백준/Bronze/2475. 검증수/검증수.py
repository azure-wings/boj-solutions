from typing import List
from functools import reduce
import sys

def sol_2475(ls: List[int]) -> int:
    return reduce(lambda acc, x: acc + x,list(map(lambda x: x**2, ls)), 0) % 10

if __name__ == "__main__":
    ls = list(map(int, sys.stdin.readline().split()))
    print(sol_2475(ls))