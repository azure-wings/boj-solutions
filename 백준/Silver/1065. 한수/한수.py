from typing import List
import sys

class Hansu():
    def __init__(self, n: int):
        self.check = [False] * n
        
    def find_all(self) -> int:
        n = len(self.check)
        for i in range(n):
            curr = str(i+1)
            gap = [None] * (len(curr)-1)
            for j in range(len(gap)):
                gap[j] = int(curr[j+1]) - int(curr[j])
            if len(set(gap)) <= 1:
                self.check[i] = True
        return len([ num for num in range(1, n+1) if self.check[num-1] ])

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    hansu = Hansu(n)
    print(hansu.find_all())