from typing import List
import sys

def sol_1764(
    never_heard_of: List[str],
    never_seen: List[str]
) -> List[str]:
    return sorted(list(set(never_heard_of).intersection(set(never_seen))))
    
if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    never_heard_of, never_seen = [None]*n, [None]*m
    for i in range(n):
        never_heard_of[i] = sys.stdin.readline().rstrip()
    for i in range(m):
        never_seen[i] = sys.stdin.readline().rstrip()
    never_seen_or_heard_of = sol_1764(never_heard_of, never_seen)
    print(len(never_seen_or_heard_of))
    for p in never_seen_or_heard_of:
        print(p)