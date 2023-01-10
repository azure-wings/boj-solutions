from functools import reduce
import sys

def ncr(n: int, r: int) -> int:
    r = min(r, n-r)
    mul = lambda x, y: x*y
    numer = reduce(mul, range(n, n-r, -1), 1)
    denom = reduce(mul, range(1, r+1), 1)
    return numer // denom

def sol_2775(k: int, n: int) -> int:
    return ncr(k+n, k+1)

if __name__ == "__main__":
    t = int(sys.stdin.readline())
    for i in range(t):
        k = int(sys.stdin.readline())
        n = int(sys.stdin.readline())
        print(sol_2775(k, n))