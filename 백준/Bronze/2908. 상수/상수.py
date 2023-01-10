import sys

def sol_2908(a: str, b: str) -> int:
    a, b = a[::-1], b[::-1]
    return a if a > b else b

if __name__ == "__main__":
    a, b = sys.stdin.readline().split()
    print(sol_2908(a, b))