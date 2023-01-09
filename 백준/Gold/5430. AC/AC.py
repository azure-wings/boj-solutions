from __future__ import annotations
from collections import deque
import sys

def sol_5430(ops: str, nums: List[int]) -> Union[None, List[int]]:
    direction = 1
    nums = deque(nums)
    for op in ops:
        if op == "R":
            direction *= -1
        elif op == "D":
            if nums:
                if direction > 0:
                    nums.popleft()
                elif direction < 0:
                    nums.pop()
            else:
                return None
    return list(nums) if direction == 1 else list(nums)[::-1]

t = int(sys.stdin.readline())
outputs = []
for i in range(t):
    ops = sys.stdin.readline().rstrip()
    n = int(sys.stdin.readline())
    if n == 0:
        _ = sys.stdin.readline()
        nums = []
    else:
        nums = sys.stdin.readline().rstrip().strip('[').strip(']').split(',')
    result = sol_5430(ops, nums)
    if result is not None:
        ans = ','.join(result)
        outputs.append(f'[{ans}]')
    else:
        outputs.append("error")
for out in outputs:
    print(out)