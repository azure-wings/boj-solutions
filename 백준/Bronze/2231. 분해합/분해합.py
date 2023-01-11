import sys

def sol_2231(n: int) -> int:
    min_gen = n
    for i in range(n, 0, -1):
        if i + sum([ int(d) for d in str(i) ]) == n:
            min_gen = i
    return min_gen if min_gen < n else 0

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    print(sol_2231(n))