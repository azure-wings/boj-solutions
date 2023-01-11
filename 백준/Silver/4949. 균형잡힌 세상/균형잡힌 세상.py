from collections import deque
import re
import sys

def sol_4949(s: str) -> bool:
    s = re.sub('[^\(\)\[\]]', '', s)
    dq = deque()
    for c in s:
        match c:
            case '('|'[':
                dq.append(c)
            case ')':
                try:
                    if dq.pop() != '(':
                        return False
                except:
                    return False
            case ']':
                try:
                    if dq.pop() != '[':
                        return False
                except:
                    return False
    return True if not dq else False

if __name__ == "__main__":
    yes, no = "yes", "no"
    while True:
        s = sys.stdin.readline().rstrip()
        if s == ".":
            break
        else:
            print(f"{yes if sol_4949(s) else no}")