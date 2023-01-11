from statistics import mean, median
from collections import Counter
from typing import List
import sys

def mode(nums: List[int]) -> int:
    if len(nums) == 1:
        return nums[0]
    counts = Counter(sorted(nums)).most_common(n=2)
    if counts[0][1] == counts[1][1]:
        return counts[1][0]
    else:
        return counts[0][0]

def sol_2108(nums: List[int]) -> None:
    print(round(mean(nums)))
    print(median(nums))
    print(mode(nums))
    print(max(nums) - min(nums))
    
if __name__ == "__main__":
    n = int(sys.stdin.readline())
    nums = [None] * n
    for i in range(n):
        nums[i] = int(sys.stdin.readline())
    sol_2108(nums)