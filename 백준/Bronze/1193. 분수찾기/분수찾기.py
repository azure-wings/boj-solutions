from typing import Tuple
import sys
import math

def sol_1193(x: int) -> Tuple[int, int]:
    n = math.ceil((math.sqrt(1 + 8*x) - 1)/2)
    if n % 2 == 0:
        numerator = x - n*(n - 1) / 2
        denominator = n + 1 - numerator
    else:
        denominator = x - n*(n - 1) / 2
        numerator = n + 1 - denominator
    return (int(numerator), int(denominator))

if __name__ == "__main__":
    x = int(sys.stdin.readline())
    frac = sol_1193(x)
    print(f'{frac[0]}/{frac[1]}')