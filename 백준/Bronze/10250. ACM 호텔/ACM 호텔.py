import sys

def sol_10250(h: int, w: int, n: int) -> str:
    if n % h:
        floor = n % h
        num = (n // h) + 1
    else:
        floor = h
        num = n // h
    return f"{floor}{num:02d}"

if __name__ == "__main__":
    t = int(sys.stdin.readline())
    for i in range(t):
        h, w, n = map(int, sys.stdin.readline().split())
        print(sol_10250(h, w, n))