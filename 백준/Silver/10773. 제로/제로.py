from typing import List
from collections import deque
import sys

def sol_10773(nums: List[int]) -> int:
    dq = deque()
    for num in nums:
        if num == 0:
            dq.pop()
        else:
            dq.append(num)
    return sum(dq)

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    nums = [None] * n
    for i in range(n):
        nums[i] = int(sys.stdin.readline())
    print(sol_10773(nums))