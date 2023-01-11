from collections import Counter
import sys
sys.setrecursionlimit(10**5)

def sol_2805(m: int, trees: Counter) -> int:
    lo, hi = 0, max(trees.items())[0]
    while lo <= hi:
        mid = (lo + hi)//2
        total = sum([(t-mid)*i for t,i in trees.items() if t > mid])
        if total >= m:
            lo = mid + 1
        elif total < m:
            hi = mid - 1
    return hi

if __name__ == "__main__":
    _, m = map(int, sys.stdin.readline().split())
    trees = Counter(map(int, sys.stdin.readline().split()))
    print(sol_2805(m, trees))