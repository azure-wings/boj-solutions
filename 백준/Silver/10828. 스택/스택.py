from __future__ import annotations
from typing import List, Tuple, Union
import sys

def sol_10828(
    inputs: List[str],
    stack: List[int]
) -> Tuple(Union(None, int), List[int]):
    op = inputs[0]
    if op == "push":
        stack.append(int(inputs[1]))
        return (None, stack)
    elif op == "pop":
        return (-1 if not stack else stack.pop(), stack)
    elif op == "size":
        return (len(stack), stack)
    elif op == "empty":
        return (1 if not stack else 0, stack)
    elif op == "top":
        return (-1 if not stack else stack[-1], stack)
    
n = int(sys.stdin.readline())
stack = []
for i in range(n):
    cmd = sys.stdin.readline().split()
    output, stack = sol_10828(cmd, stack)
    if output is not None:
        print(output) 