from typing import List
import sys

def sol_1929(m: int, n: int) -> List[int]:
    primes = [True] * 1_000_001
    primes[0] = False
    primes[1] = False
    for i in range(2, 1_000_001):
        for j in range(2*i, 1_000_001, i):
            primes[j] = False
    return [ i for i in range(m, n+1) if primes[i] ]

if __name__ == "__main__":
    m, n = map(int, sys.stdin.readline().split())
    primes = sol_1929(m, n)
    for p in primes:
        print(p)