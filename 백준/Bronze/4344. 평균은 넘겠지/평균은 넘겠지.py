from typing import List
from statistics import mean
import sys

def sol_4344(ls: List[int]) -> int:
    avg = mean(ls)
    return len(list(filter(lambda x: x > avg, ls))) / len(ls)

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    for i in range(n):
        ls = list(map(int, sys.stdin.readline().split()))[1:]
        print(f'{sol_4344(ls)*100:.3f}%')