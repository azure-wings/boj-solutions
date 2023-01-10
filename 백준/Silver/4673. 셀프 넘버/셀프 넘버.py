from typing import List
import sys

class SelfNumber():
    def __init__(self):
        self.check = [False] * 10000
        
    def find_all(self, n: int) -> None:
        curr = n
        while True:
            curr += sum(list(map(int, str(curr))))
            try:
                if self.check[curr - 1]:
                    break
                else:
                    self.check[curr - 1] = True
            except IndexError:
                break

if __name__ == "__main__":
    selfnum = SelfNumber()
    for i in range(1, 10001):
        selfnum.find_all(i)
    nums = filter(lambda x: not x[1], list(zip(list(range(1, 10001)), selfnum.check)))
    for num in list(nums):
        print(num[0])