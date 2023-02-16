import sys
from typing import Tuple, List

def input_function() -> Tuple[str, str]:
    s1: str = sys.stdin.readline().rstrip()
    s2: str = sys.stdin.readline().rstrip()

    return s1, s2

def longest_common_subsequence(s1: str, s2: str) -> int:
    memo: List[List[int]] = [[0 for _ in range(len(s2) + 1)] for _ in range(len(s1) + 1)]
    lcs: str = ""

    for i in range(1, len(s1) + 1):
        for j in range(1, len(s2) + 1):
            if s1[i-1] == s2[j-1]:
                memo[i][j] = memo[i-1][j-1] + 1
            else:
                memo[i][j] = max(memo[i-1][j], memo[i][j-1])

    return memo[-1][-1]

if __name__ == "__main__":
    s1: str; s2: str
    s1, s2 = input_function()
    print(longest_common_subsequence(s1, s2))