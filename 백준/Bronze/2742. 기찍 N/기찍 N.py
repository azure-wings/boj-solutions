import sys

def sol_2742(n: int) -> None:
    for i in range(n, 0, -1):
        print(i)
        
if __name__ == "__main__":
    n = int(sys.stdin.readline())
    sol_2742(n)