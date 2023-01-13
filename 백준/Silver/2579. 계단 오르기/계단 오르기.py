from typing import List
from collections import defaultdict
import sys

def sol_2579(scores: List[int], n: int) -> int:
    if n in {1, 2}:
        return sum(scores)
        
    memos = [defaultdict(lambda: 0), defaultdict(lambda: 0)]
    memos[0][1] = scores[0]
    memos[0][2] = scores[1]
    memos[1][2] = scores[0] + scores[1]

    for i in range(3, n+1):
        memos[0][i] = max(memos[0][i-2], memos[1][i-2]) + scores[i-1]
        memos[1][i] = memos[0][i-1] + scores[i-1] if memos[0][i-1] else 0

    return max(memos[0][n], memos[1][n])

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    scores = [None] * n
    for i in range(n):
        scores[i] = int(sys.stdin.readline())
    print(sol_2579(scores, n))