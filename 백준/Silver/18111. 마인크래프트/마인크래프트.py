from typing import List, Tuple
import sys

def sol_18111(blocks: List[List[int]], inventory: int) -> Tuple[int, int]:
    n, m = len(blocks), len(blocks[0])
    min_time = sys.maxsize
    target_lvl = -1
    for lvl in range(257):
        required, obtainable = 0, 0
        for i in range(n):
            for j in range(m):
                if blocks[i][j] > lvl:
                    obtainable += blocks[i][j] - lvl
                else:
                    required += lvl - blocks[i][j]
        if required > inventory + obtainable:
            continue
        else:
            new_time = required + 2*obtainable
            if min_time >= new_time:
                min_time = new_time
                target_lvl = lvl
    return min_time, target_lvl

if __name__ == "__main__":
    n, m, b = map(int, sys.stdin.readline().split())
    blocks = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
    print(*sol_18111(blocks, b))