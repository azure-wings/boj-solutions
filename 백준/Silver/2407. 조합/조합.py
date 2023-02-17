import sys
import math

if __name__ == "__main__":
    n: int; r: int
    n, r = map(int, sys.stdin.readline().split())
    print(math.comb(n, r))