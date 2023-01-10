import sys

def sol_11720(s: str) -> int:
    return sum(list(map(int, s)))

if __name__ == "__main__":
    _ = sys.stdin.readline()
    s = sys.stdin.readline().rstrip()
    print(sol_11720(s))