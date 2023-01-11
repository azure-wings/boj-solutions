from typing import List, Tuple
import sys

def sol_10814(mems: List[Tuple[str, str]]) -> List[Tuple[str, str]]:
    return sorted(mems, key=lambda x: int(x[0]))

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    mems = [None] * n
    for i in range(n):
        member = tuple(sys.stdin.readline().split())
        mems[i] = member
    mem_sorted = sol_10814(mems)
    for mem in mem_sorted:
        print(*mem)