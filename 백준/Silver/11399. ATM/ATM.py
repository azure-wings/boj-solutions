from typing import List
from functools import reduce
import sys

def sol_11399(times: List[int]) -> int:
    n = len(times)
    return reduce(lambda acc, ix: acc + (n-ix[0])*ix[1], enumerate(sorted(times)), 0)

if __name__ == "__main__":
    _ = sys.stdin.readline()
    times = list(map(int, sys.stdin.readline().split()))
    print(sol_11399(times))