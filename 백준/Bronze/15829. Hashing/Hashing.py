from functools import reduce
import sys

atoi = { chr(i+96):i for i in range(1, 27) }
r = 31
M = 1234567891

def sol_15829(s: str) -> int:
    hashed = reduce(lambda acc, xs: acc + atoi[xs[1]]*r**xs[0], enumerate(s), 0)
    return hashed % M

if __name__ == "__main__":
    _ = sys.stdin.readline()
    s = sys.stdin.readline().rstrip()
    print(sol_15829(s))