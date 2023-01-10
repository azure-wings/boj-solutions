from typing import List
import sys

def sol_10809(s: str) -> List[int]:
    result = [-1] * 26
    for i in range(97, 123):
        try:
            result[i-97] = s.index(chr(i))
        except:
            pass
    return result

if __name__ == "__main__":
    s = sys.stdin.readline().rstrip()
    print(*sol_10809(s))