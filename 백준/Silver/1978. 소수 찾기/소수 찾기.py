from typing import List
import sys

def sol_1978() -> List[int]:
    primes = [True] * 1001
    primes[0] = False
    primes[1] = False
    for i in range(2, 1001):
        for j in range(2*i, 1001, i):
            primes[j] = False
    return [ i for i in range(1001) if primes[i] ]

if __name__ == "__main__":
    _ = sys.stdin.readline()
    ls = list(map(int, sys.stdin.readline().split()))
    primes = sol_1978()
    ls = [ num for num in ls if num in primes ]
    print(len(ls))