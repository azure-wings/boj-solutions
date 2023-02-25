import sys
from collections import deque
from typing import List, Deque

def bfs(start: int, target: int) -> int:
    times: List[int] = [-1 for _ in range(100_001)]
    visiting: Deque[int] = deque()

    times[start] = 0
    visiting.append(start)

    while visiting:
        curr: int = visiting.popleft()
        if curr == target:
            return times[curr]
        
        else:
            if 0 < 2*curr < 100_001 and times[2*curr] == -1:
                visiting.appendleft(2*curr)
                times[2*curr] = times[curr]

            if 0 <= curr-1 < 100_001 and times[curr-1] == -1:
                visiting.append(curr-1)
                times[curr-1] = times[curr] + 1

            if 0 <= curr+1 < 100_001 and times[curr+1] == -1:
                visiting.append(curr+1)
                times[curr+1] = times[curr] + 1

if __name__ == "__main__":
    start: int; target: int
    start, target = map(int, sys.stdin.readline().split())
    print(bfs(start, target))