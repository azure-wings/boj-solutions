import sys

def sol_2741(n: int) -> None:
    for i in range(n):
        print(i+1)
        
if __name__ == "__main__":
    n = int(sys.stdin.readline())
    sol_2741(n)