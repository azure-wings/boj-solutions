import sys
from typing import List


def ball_in_basket(n: int, m: int) -> List[int]:
    baskets: List[int] = [0] * (n + 1)

    for _ in range(m):
        start, end, num = map(int, sys.stdin.readline().split())
        baskets[start : end + 1] = [num for _ in range(start, end + 1)]

    return baskets[1:]


if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    print(*ball_in_basket(n, m))
