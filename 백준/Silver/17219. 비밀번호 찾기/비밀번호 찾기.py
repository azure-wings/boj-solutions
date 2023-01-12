import sys

if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    passwords = {}
    for _ in range(n):
        input = sys.stdin.readline().split()
        passwords[input[0]] = input[1]
    for _ in range(m):
        query = sys.stdin.readline().rstrip()
        print(passwords[query])