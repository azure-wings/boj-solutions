import sys

def sol_10757(a: int, b: int) -> int:
    return a + b

if __name__ == "__main__":
    a, b = map(int, sys.stdin.readline().split())
    print(sol_10757(a, b))