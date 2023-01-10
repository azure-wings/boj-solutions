from typing import List
import sys

def sol_1152(ls: List[str]) -> int:
    return len(ls)

if __name__ == "__main__":
    s = sys.stdin.readline().split()
    print(sol_1152(s))