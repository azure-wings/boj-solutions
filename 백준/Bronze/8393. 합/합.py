import sys

def sol_8393(n: int) -> int:
    return n*(n + 1) // 2

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    print(sol_8393(n))