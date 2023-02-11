from __future__ import annotations
import sys

def sol_25083(a: int, b: int) -> str:
    if a > b:
        return ">"
    elif a < b:
        return "<"
    else:
        return "=="

if __name__ == "__main__":
    a, b = map(int, sys.stdin.readline().split())
    print(sol_25083(a, b))