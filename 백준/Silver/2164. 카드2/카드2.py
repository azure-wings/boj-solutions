from collections import deque
import sys

def sol_2164(n: int) -> int:
    dq = deque(range(1, n+1))
    while len(dq) > 1:
        dq.popleft()
        if len(dq) == 1:
            break
        dq.append(dq.popleft())
    return dq[0]

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    print(sol_2164(n))