from typing import List
import sys

def sol_8958(s: str) -> int:
    score, acc = 0, 0
    for c in s:
        match c:
            case 'O':
                acc += 1
                score += acc
            case 'X':
                acc = 0
    return score

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    for i in range(n):
        s = sys.stdin.readline().rstrip()
        print(sol_8958(s))