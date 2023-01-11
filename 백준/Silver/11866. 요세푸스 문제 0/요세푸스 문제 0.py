from typing import List
import sys

def sol_11866(n: int, k: int) -> List[str]:
    josephus = []
    given = [ i for i in range(1, n+1) ]
    del_idx = 0
    while given:
        del_idx += k - 1
        if del_idx >= len(given):
            del_idx %= len(given)
        josephus.append(str(given.pop(del_idx)))
    return josephus

if __name__ == "__main__":
    n, k = map(int, sys.stdin.readline().split())
    josephus = sol_11866(n, k)
    print(f'<{", ".join(josephus)}>')