from typing import List
import sys

def sol_2920(ls: List[int]) -> str:
    if ls == list(range(1, 9)):
        return "ascending"
    elif ls == list(range(8, 0, -1)):
        return "descending"
    else:
        return "mixed"
    
if __name__ == "__main__":
    ls = list(map(int, sys.stdin.readline().split()))
    print(sol_2920(ls))