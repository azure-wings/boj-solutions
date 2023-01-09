from __future__ import annotations
from typing import List, Tuple, Union
import sys

def sol_10845(
    inputs: List[str],
    queue: List[int]
) -> Tuple(Union(None, int), List[int]):
    op = inputs[0]
    if op == "push":
        queue.insert(0, inputs[1])
        return (None, queue)
    elif op == "pop":
        return (-1 if not queue else queue.pop(), queue)
    elif op == "size":
        return (len(queue), queue)
    elif op == "empty":
        return (1 if not queue else 0, queue)
    elif op == "front":
        return (-1 if not queue else queue[-1], queue)
    elif op == "back":
        return (-1 if not queue else queue[0], queue)
    
n = int(sys.stdin.readline())
queue = []
for i in range(n):
    cmd = sys.stdin.readline().split()
    output, queue = sol_10845(cmd, queue)
    if output is not None:
        print(output) 