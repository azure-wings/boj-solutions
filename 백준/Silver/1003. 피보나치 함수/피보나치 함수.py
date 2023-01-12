from collections import defaultdict
import sys

class Fibonacci():
    def __init__(self):
        self.memo = defaultdict()
        self.memo[0] = 0
        self.memo[1] = 1
    
    def compute(self, n: int) -> None:
        for i in range(2, n+1):
            self.memo[i] = self.memo[i-1] + self.memo[i-2]

if __name__ == "__main__":
    t = int(sys.stdin.readline())
    fib = Fibonacci()
    max = 0
    for i in range(t):
        n = int(sys.stdin.readline())
        if n == 0:
            print("1 0")
            continue
        elif n == 1:
            print("0 1")
            continue
        elif n > max:
            fib.compute(n)
        print(f"{fib.memo[n-1]} {fib.memo[n]}")