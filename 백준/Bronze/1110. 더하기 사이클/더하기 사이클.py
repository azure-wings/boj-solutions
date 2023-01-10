import sys

def sol_10951(n: int) -> int:
    count = 0
    change = n
    while True:
        count += 1
        s = f'{change:02d}'
        change = (change % 10)*10 + (int(s[0]) + int(s[1])) % 10
        if change == n:
            break
    return count

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    print(sol_10951(n))