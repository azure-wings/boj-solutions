from typing import List, Tuple
import sys

def sol_10871(ls: List[int]) -> Tuple[int, int]:
    return min(ls), max(ls)

if __name__ == "__main__":
    _ = sys.stdin.readline()
    ls = list(map(int, sys.stdin.readline().split()))
    print(*sol_10871(ls))