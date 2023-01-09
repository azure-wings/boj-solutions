from __future__ import annotations
import sys

def sol_1874(seq: List[int]) -> Union[None, List[str]]:
    target = []
    reserve = []
    given = list(range(len(seq), 0, -1))
    cursor = 0
    operations = []
    while(cursor < len(seq)):
        if (not reserve) or reserve[-1] < seq[cursor]:
            try:
                take_new = given.pop()
            except:
                return None
            reserve.append(take_new)
            operations.append("+")
        elif reserve[-1] == seq[cursor]:
            target.append(reserve.pop())
            operations.append("-")
            cursor += 1
        else:
            return None
    return operations
            
n = int(sys.stdin.readline())
seq = []
for i in range(n):
    seq.append(int(sys.stdin.readline()))
operations = sol_1874(seq)
if operations:
    for op in operations:
        print(op)
else:
    print("NO")