import sys

def sol_1259(n: int) -> bool:
    s = str(n)
    return s == s[::-1]

if __name__ == "__main__":
    yes, no = "yes", "no"
    while True:
        n = int(sys.stdin.readline())
        if n == 0:
            break
        else:
            print(f"{yes if sol_1259(n) else no}")