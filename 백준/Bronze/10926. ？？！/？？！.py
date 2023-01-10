from __future__ import annotations
import sys

def sol_10926(s: str) -> str:
    return s + "??!"

if __name__ == "__main__":
    username = sys.stdin.readline().rstrip()
    sys.stdout.write(sol_10926(username))