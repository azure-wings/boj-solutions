from typing import List, Tuple
import sys

def sol_10950(nums: List[List[int]]) -> List[int]:
    return map(sum, nums)

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    nums = [None] * n
    for i in range(n):
        nums[i] = list(map(int, sys.stdin.readline().split()))
    results = sol_10950(nums)
    for ret in results:
        print(ret)