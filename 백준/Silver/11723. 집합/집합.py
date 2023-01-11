from typing import List
import sys

class MySet():
    def __init__(self):
        self.myset = set()
    
    def add(self, x: int) -> None:
        self.myset.add(x)
        
    def remove(self, x: int) -> None:
        try:
            self.myset.remove(x)
        except:
            pass
    
    def check(self, x: int) -> None:
        print(f"{1 if x in self.myset else 0}")
        
    def toggle(self, x: int) -> None:
        if x in self.myset:
            self.myset.remove(x)
        else:
            self.myset.add(x)
            
    def all(self) -> None:
        self.myset = set(range(1, 21))
        
    def empty(self) -> None:
        self.myset = set()
        
def sol_11723(s: List[str], myset: MySet) -> None:
    if s[0] == "add":
        myset.add(int(s[1]))
    elif s[0] == "remove":
        myset.remove(int(s[1]))
    elif s[0] == "check":
        myset.check(int(s[1]))
    elif s[0] == "toggle":
        myset.toggle(int(s[1]))
    elif s[0] == "all":
        myset.all()
    elif s[0] == "empty":
        myset.empty()
        
if __name__ == "__main__":
    n = int(sys.stdin.readline())
    myset = MySet()
    for _ in range(n):
        sol_11723(sys.stdin.readline().split(), myset)