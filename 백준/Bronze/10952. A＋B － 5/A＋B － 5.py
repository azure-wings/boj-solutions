from typing import List
import sys

def sol_10952(nums: List[List[int]]) -> List[int]:
    return map(sum, nums)

if __name__ == "__main__":
    nums = []
    while True:
        inputs = list(map(int, sys.stdin.readline().split()))
        if inputs != [0, 0]:
            nums.append(inputs)
        else:
            break
    results = sol_10952(nums)
    for ret in results:
        print(ret)