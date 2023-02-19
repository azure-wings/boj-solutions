import sys

if __name__ == "__main__":
    a: int; b: int; c: int
    a, b, c = map(int, sys.stdin.readline().split())
    print(a + b + c)