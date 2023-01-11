import sys

def sol_1676(n: int) -> int:
    return (n // 5) + (n // 25) + (n // 125)

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    print(sol_1676(n))