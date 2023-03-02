import sys
import copy
from typing import List

def input_function() -> List[List[int]]:
    stickers: List[List[int]] = [None] * 2
    n: int = int(sys.stdin.readline())
    for i in range(2):
        stickers[i] = list(map(int, sys.stdin.readline().split()))

    return stickers

def dp(stickers: List[List[int]]) -> int:
    n: int = len(stickers[0])
    memo: List[List[int]] = copy.deepcopy(stickers)
    
    for i in range(1, n):
        if i == 1:
            memo[0][i] += memo[1][0]
            memo[1][i] += memo[0][0]
        else:
            memo[0][i] += max(memo[1][i-1] , memo[1][i-2])
            memo[1][i] += max(memo[0][i-1] , memo[0][i-2])

    return max(memo[0][-1], memo[1][-1])


if __name__ == "__main__":
    tc: int = int(sys.stdin.readline())
    for i in range(tc):
        print(dp(input_function()))