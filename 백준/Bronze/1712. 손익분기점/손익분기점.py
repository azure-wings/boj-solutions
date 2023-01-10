import sys

def sol_1712(fc: int, vc: int, p: int) -> int:
    try:
        return (fc // (p - vc)) + 1
    except:
        return -1

if __name__ == "__main__":
    fc, vc, p = map(int, sys.stdin.readline().split())
    result = sol_1712(fc, vc, p)
    print(f'{result if result > 0 else -1}')