from collections import defaultdict
import sys

def sol_1463(n: int) -> int:
    memo = defaultdict(lambda: 0)
    for i in range(2, n+1):
        match i % 6:
            case 0:
                memo[i] = min(memo[i-1], memo[i//3], memo[i//2]) + 1
            case 2 | 4:
                memo[i] = min(memo[i-1], memo[i//2]) + 1
            case 3:
                memo[i] = min(memo[i-1], memo[i//3]) + 1
            case _:
                memo[i] = memo[i-1] + 1
    return memo[n]

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    print(sol_1463(n))