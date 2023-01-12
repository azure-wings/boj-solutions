from typing import List
from functools import reduce
import sys

def sol_11399(times: List[int]) -> int:
    return reduce(lambda acc, x: acc + x[0]*x[1], zip(sorted(times), range(len(times), 0, -1)), 0)

if __name__ == "__main__":
    _ = sys.stdin.readline()
    times = list(map(int, sys.stdin.readline().split()))
    print(sol_11399(times))