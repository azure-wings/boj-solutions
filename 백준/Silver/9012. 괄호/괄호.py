from __future__ import annotations
import sys

def sol_9012(s: str) -> bool:
    stack = []
    for c in s:
        if c == "(":
            stack.append(c)
        else:
            try:
                stack.pop()
            except:
                return False
    return True if not stack else False

n = int(sys.stdin.readline())
yes, no = "YES", "NO"
for i in range(n):
    s = sys.stdin.readline().rstrip()
    print(f"{yes if sol_9012(s) else no}")