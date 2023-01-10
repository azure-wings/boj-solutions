from typing import List
from collections import Counter
import sys

def sol_2577(a: int, b: int, c: int) -> List[int]:
    counts = Counter(str(a * b * c))
    return [ counts[str(i)] for i in range(10) ]

if __name__ == "__main__":
    a = int(sys.stdin.readline())
    b = int(sys.stdin.readline())
    c = int(sys.stdin.readline())
    counts = sol_2577(a, b, c)
    for num in counts:
        print(num)