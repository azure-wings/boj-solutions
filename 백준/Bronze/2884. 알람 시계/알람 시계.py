from typing import List
import sys

def sol_2884(time: List[int]) -> List[int]:
    new_time = [0, 0]
    new_time[1] = (time[1] - 45) % 60
    new_time[0] = (time[0] + ((time[1] - 45) // 60)) % 24
    return new_time

if __name__ == "__main__":
    time = list(map(int, sys.stdin.readline().split()))
    print(*sol_2884(time))