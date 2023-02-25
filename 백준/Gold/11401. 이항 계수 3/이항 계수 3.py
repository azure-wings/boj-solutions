import sys

def factorial(n: int, mod: int = 1_000_000_007) -> int:
    result: int = 1
    for i in range(1, n+1):
        result = (result * i) % mod

    return result

def fast_power(base: int, exp: int, mod: int = 1_000_000_007) -> int:
    if exp == 0:
        return 1
    elif exp % 2 == 0:
        return fast_power(base, exp//2)**2 % mod
    else:
        return (fast_power(base, exp//2)**2 * base) % mod

if __name__ == "__main__":
    n: int; k: int; mod: int
    n, k = map(int, sys.stdin.readline().split())
    mod = 1_000_000_007
    print(factorial(n) * fast_power(factorial(k), mod - 2) * fast_power(factorial(n-k), mod - 2) % mod)