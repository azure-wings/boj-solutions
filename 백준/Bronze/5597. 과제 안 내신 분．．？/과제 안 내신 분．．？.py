from typing import List, Tuple
import sys

def sol_2562(ls: List[int]) -> List[int]:
    all_students = set(range(1, 31))
    result = list(all_students.difference(set(ls)))
    result.sort()
    return result

if __name__ == "__main__":
    ls = [None] * 28
    for i in range(28):
        ls[i] = int(sys.stdin.readline())
    result = sol_2562(ls)
    for ret in result:
        print(ret)