from typing import List
import sys

def sol_1158(n: int, k: int) -> List[int]:
    josephus = []
    given = list(range(1, n+1))
    del_idx = k - 1
    while True:
        removed = given.pop(del_idx)
        josephus.append(removed)
        if len(given):
            del_idx = (del_idx + k - 1) % len(given)
        else:
            break
    return josephus

if __name__ == "__main__":
    n, k = map(int, sys.stdin.readline().split())
    josephus = sol_1158(n, k)
    print(f'<{str(josephus)[1:-1]}>')