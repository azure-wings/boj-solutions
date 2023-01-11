import sys

def sol_2231(n: int) -> int:
    min_gen = 0
    for i in range(max(0, n - 9*len(str(n))), n):
        if i + sum([ int(d) for d in str(i) ]) == n:
            min_gen = i
            break
    return min_gen

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    print(sol_2231(n))