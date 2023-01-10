import sys
import math

def sol_2869(a: int, b: int, v: int) -> int:
    return int(math.ceil(1 + (v - a)/(a - b)))

if __name__ == "__main__":
    a, b, v = map(int, sys.stdin.readline().split())
    print(sol_2869(a, b, v))