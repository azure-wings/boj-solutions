from typing import List
import sys

def sol_1978() -> List[int]:
    primes = [True] * 10001
    primes[0] = False
    primes[1] = False
    for i in range(2, 10001):
        for j in range(2*i, 10001, i):
            primes[j] = False
    return [ i for i in range(10001) if primes[i] ]

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    m = int(sys.stdin.readline())
    ls = range(n, m+1)
    primes = sol_1978()
    ls = [ num for num in ls if num in primes ]
    if ls:
        print(sum(ls))
        print(ls[0])
    else:
        print(-1)