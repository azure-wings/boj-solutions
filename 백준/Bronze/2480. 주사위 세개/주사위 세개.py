from typing import List
import sys

def sol_2480(die: List[int]) -> int:
    counts = [ die.count(dice) for dice in die ]
    zipped = set(zip(die, counts))
    match len(zipped):
        case 1:
            popped = zipped.pop()
            return 10000 + popped[0]*1000
        case 2:
            popped = zipped.pop()
            if popped[1] != 2:
                popped = zipped.pop()
            return 1000 + popped[0]*100
        case 3:
            return max(die)*100

if __name__ == "__main__":
    die = list(map(int, sys.stdin.readline().split()))
    print(sol_2480(die))