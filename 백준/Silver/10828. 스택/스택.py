from __future__ import annotations
import sys

class Node:
    def __init__(self, item: int, next: Node):
        self.item = item
        self.next = next

class Stack:
    def __init__(self):
        self.last = None
        self.size = 0
        
    def push(self, item: int):
        self.last = Node(item, self.last)
        self.size += 1
        
    def pop(self) -> int:
        if self.size == 0:
            return -1
        else:
            item = self.last.item
            self.last = self.last.next
            self.size -= 1
            return item
    
    def _size(self) -> int:
        return self.size
    
    def empty(self) -> int:
        return 1 if self.size == 0 else 0
    
    def top(self) -> int:
        return -1 if self.size == 0 else self.last.item
    
n = int(sys.stdin.readline())
stack = Stack()
for i in range(n):
    inputs = sys.stdin.readline().split()
    if inputs[0] == "push":
        stack.push(int(inputs[1]))
    elif inputs[0] == "pop":
        print(stack.pop())
    elif inputs[0] == "size":
        print(stack._size())
    elif inputs[0] == "empty":
        print(stack.empty())
    elif inputs[0] == "top":
        print(stack.top())