import sys

def gcd(a: int, b: int) -> int:
    return gcd(b % a, a) if b % a else a

def lcm(a: int, b: int, gcd: int) -> int:
    return b * (a // gcd)

if __name__ == "__main__":
    a, b = map(int, sys.stdin.readline().split())
    gcd = gcd(a, b)
    lcm = lcm(a, b, gcd)
    print(gcd)
    print(lcm)