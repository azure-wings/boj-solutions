import sys
from collections import deque
from typing import Deque, Tuple

def bfs(init: int, target: int) -> int:
    visiting: Deque[Tuple[int, int]] = deque()
    visiting.append((init, 1))

    while visiting:
        curr_num: int; curr_cnt: int
        curr_num, curr_cnt = visiting.pop()

        if curr_num == target:
            return curr_cnt
        elif curr_num < target:
            continue
        else:
            if curr_num % 10 == 1:
                visiting.append((curr_num // 10, curr_cnt + 1))
            if curr_num % 2 == 0:
                visiting.append((curr_num // 2, curr_cnt + 1))

    return -1

if __name__ == "__main__":
    target: int; init: int
    target, init = map(int, sys.stdin.readline().split())
    print(bfs(init, target))