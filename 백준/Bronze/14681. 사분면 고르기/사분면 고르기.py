import sys

def sol_14681(x: int, y: int) -> int:
    match (x > 0, y > 0):
        case (True, True):
            return 1
        case (False, True):
            return 2
        case (False, False):
            return 3
        case (True, False):
            return 4
        
if __name__ == "__main__":
    x = int(sys.stdin.readline())
    y = int(sys.stdin.readline())
    print(sol_14681(x, y))