import sys

def sol_1085(x: int, y: int, w: int, h: int) -> int:
    return min(x, w - x, y, h - y)

if __name__ == "__main__":
    x, y, w, h = map(int, sys.stdin.readline().split())
    print(sol_1085(x, y, w, h))