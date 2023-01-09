from __future__ import annotations
import sys

class Node:
    def __init__(self, item: int, next: Node):
        self.item = item
        self.next = next

class Queue:
    def __init__(self):
        self.front = None
        self.back  = None
        self.size  = 0
        
    def push(self, item: int):
        new_node = Node(item, None)
        if self.size == 0:
            self.front = new_node
            self.back  = new_node
        else:
            self.back.next = new_node
            self.back = new_node
        self.size += 1
        
    def pop(self) -> int:
        if self.size == 0:
            return -1
        else:
            item = self.front.item
            self.front = self.front.next
            if self.size == 1:
                self.back = None
            self.size -= 1
            return item
    
    def _size(self) -> int:
        return self.size
    
    def empty(self) -> int:
        return 1 if self.size == 0 else 0
    
    def _front(self) -> int:
        return -1 if self.size == 0 else self.front.item
    
    def _back(self) -> int:
        return -1 if self.size == 0 else self.back.item
    
n = int(sys.stdin.readline())
queue = Queue()
for i in range(n):
    inputs = sys.stdin.readline().split()
    if inputs[0] == "push":
        queue.push(int(inputs[1]))
    elif inputs[0] == "pop":
        print(queue.pop())
    elif inputs[0] == "size":
        print(queue._size())
    elif inputs[0] == "empty":
        print(queue.empty())
    elif inputs[0] == "front":
        print(queue._front())
    elif inputs[0] == "back":
        print(queue._back())