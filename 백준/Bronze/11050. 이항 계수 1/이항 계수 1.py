from functools import reduce
import sys

def sol_11050(n: int, r: int) -> int:
    r = min(r, n-r)
    mul = lambda x, y: x*y
    numer = reduce(mul, range(n, n-r, -1), 1)
    denom = reduce(mul, range(1, r+1), 1)
    return numer // denom

if __name__ == "__main__":
    n, r = map(int, sys.stdin.readline().split())
    print(sol_11050(n, r))