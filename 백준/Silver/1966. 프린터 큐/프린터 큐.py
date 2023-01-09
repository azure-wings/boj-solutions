from __future__ import annotations
from collections import deque 
import sys

def sol_1966(pri_list: List[int], query: int) -> int:
    idx_list = list(range(len(pri_list)))
    zip_deque = deque(list(zip(idx_list, pri_list)))
    query = zip_deque[query]
    count = 0
    while query in zip_deque:
        next = zip_deque.popleft()
        if list(filter(lambda x: x[1] > next[1], list(zip_deque))):
            zip_deque.append(next)
        else:
            count += 1
    return count

num_tc = int(sys.stdin.readline())
for i in range(num_tc):
    n, q = map(int, sys.stdin.readline().split())
    pri_list = list(map(int, sys.stdin.readline().split()))
    print(sol_1966(pri_list, q))