import sys

def sol_2839(n: int) -> int:
    match n % 5:
        case 0:
            return n // 5
        case 1 if n - 6 > 0:
            return (n - 6) // 5 + 2
        case 2 if n - 12 > 0:
            return (n - 12) // 5 + 4
        case 3 if n - 3 > 0:
            return (n - 3) // 5 + 1
        case 4 if n - 9 > 0:
            return (n - 9) // 5 + 3
        case _:
            if n % 3 == 0:
                return n // 3
            else:
                return -1

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    print(sol_2839(n))