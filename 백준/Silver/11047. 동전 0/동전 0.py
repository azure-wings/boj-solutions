from typing import List
import sys

def sol_11047(coins: List[int], k: int) -> int:
    count = 0
    for c in coins:
        if k // c:
            count += k // c
            k -= (k // c)*c
    return count

if __name__ == "__main__":
    n, k = map(int, sys.stdin.readline().split())
    coins = [None] * n
    for i in range(n):
        coins[n-i-1] = int(sys.stdin.readline())
    print(sol_11047(coins, k))