from typing import List
import sys

def sol_1316(ls: List[str]) -> int:
    count = 0
    for s in ls:
        reduced = []
        slen = len(s)
        for i in range(slen):
            if i < slen - 1 and s[i] == s[i+1]:
                pass
            else:
                reduced.append(s[i])
        if len(set(s)) == len(reduced):
            count += 1
    return count

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    ls = [None] * n
    for i in range(n):
        ls[i] = sys.stdin.readline().rstrip()
    print(sol_1316(ls))