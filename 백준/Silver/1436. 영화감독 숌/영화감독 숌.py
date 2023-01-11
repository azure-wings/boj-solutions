import sys

def sol_1436(n: int) -> int:
    doom = 666
    while n:
        if "666" in str(doom):
            n -= 1
        doom += 1
    return doom - 1

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    print(sol_1436(n))