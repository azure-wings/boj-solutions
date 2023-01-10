import sys

def sol_2292(n: int) -> int:
    room, count = 1, 1
    while n > room:
        room += 6*count
        count += 1
    return count

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    print(sol_2292(n))