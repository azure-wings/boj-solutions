import sys

def sol_2753(year: int) -> int:
    match (year % 4, year % 100, year % 400):
        case (0, 0, 0):
            return 1
        case (0, 0, _):
            return 0
        case (0, _, _):
            return 1
        case (_, _, _):
            return 0
        
if __name__ == "__main__":
    year = int(sys.stdin.readline())
    print(sol_2753(year))