from typing import List
from collections import Counter
from itertools import groupby
import sys

def sol_1157(s: str) -> List[str]:
    s = s.upper()
    freqs = groupby(Counter(list(s)).most_common(), lambda x: x[1])
    return [ val for val, _ in next(freqs)[1] ]

if __name__ == "__main__":
    s = sys.stdin.readline().rstrip()
    ret = sol_1157(s)
    if len(ret) > 1:
        print("?")
    else:
        print(*ret)