import sys

def sol_2739(n: int) -> None:
    for i in range(1, 10):
        print(f"{n} * {i} = {n*i}")
        
if __name__ == "__main__":
    n = int(sys.stdin.readline())
    sol_2739(n)