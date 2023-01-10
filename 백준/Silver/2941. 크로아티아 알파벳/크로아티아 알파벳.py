from typing import List
import sys

def sol_2941(s: str) -> int:
    count = 0
    i = 0
    while i < len(s):
        count += 1
        try:
            if s[i] == "c":
                if s[i+1] in {"=", "-"}:
                    i += 1
            elif s[i] == "d":
                if s[i+1] == "-":
                    i += 1
                elif s[i+1] == "z" and s[i+2] == "=":
                    i += 2
            elif s[i] in {"l", "n"}:
                if s[i+1] == "j":
                    i += 1
            elif s[i] in {"s", "z"}:
                if s[i+1] == "=":
                    i += 1
        except:
            pass
        i += 1
    return count

if __name__ == "__main__":
    s = sys.stdin.readline().rstrip()
    print(sol_2941(s))