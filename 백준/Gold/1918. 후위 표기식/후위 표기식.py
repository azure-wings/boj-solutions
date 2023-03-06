import sys
from collections import deque
from typing import Dict, Deque


def infix_to_postfix(s: str) -> str:
    op_pri: Dict[str, int] = {"(": 3, "*": 1, "/": 1, "+": 2, "-": 2}
    result: str = ""
    op_que: Deque[str] = deque()
    s = list(s[::-1])

    while s:
        curr: str = s.pop()
        if curr.isalpha():
            result += curr
        else:
            if curr == "(":
                op_que.append(curr)
            elif curr == ")":
                while op_que:
                    if op_que[-1] == "(":
                        op_que.pop()
                        break
                    else:
                        result += op_que.pop()
            else:
                while op_que and op_pri[op_que[-1]] <= op_pri[curr]:
                    result += op_que.pop()
                else:
                    op_que.append(curr)

    while op_que:
        result += op_que.pop()

    return result


if __name__ == "__main__":
    print(infix_to_postfix(sys.stdin.readline().rstrip()))
