from __future__ import annotations
import sys

class Node:
    def __init__(self, item: int, prev: Node, next: Node):
        self.item = item
        self.prev = prev
        self.next = next

class DEQueue:
    def __init__(self):
        self.front = None
        self.back  = None
        self.size  = 0
        
    def push_front(self, item: int):
        new_node = Node(item, None, self.front)
        if self.size == 0:
            self.front = new_node
            self.back  = new_node
        else:
            self.front.prev = new_node
            self.front = new_node
        self.size += 1
        
    def push_back(self, item: int):
        new_node = Node(item, self.back, None)
        if self.size == 0:
            self.front = new_node
            self.back  = new_node
        else:
            self.back.next = new_node
            self.back = new_node
        self.size += 1
        
    def pop_front(self) -> int:
        if self.size == 0:
            return -1
        else:
            item = self.front.item
            self.front = self.front.next
            if self.size == 1:
                self.back = None
            else:
                self.front.prev = None
            self.size -= 1
            return item
    
    def pop_back(self) -> int:
        if self.size == 0:
            return -1
        else:
            item = self.back.item
            self.back = self.back.prev
            if self.size == 1:
                self.front = None
            else:
                self.back.next = None
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
dequeue = DEQueue()
for i in range(n):
    inputs = sys.stdin.readline().split()
    if inputs[0] == "push_front":
        dequeue.push_front(int(inputs[1]))
    elif inputs[0] == "push_back":
        dequeue.push_back(int(inputs[1]))
    elif inputs[0] == "pop_front":
        print(dequeue.pop_front())
    elif inputs[0] == "pop_back":
        print(dequeue.pop_back())
    elif inputs[0] == "size":
        print(dequeue._size())
    elif inputs[0] == "empty":
        print(dequeue.empty())
    elif inputs[0] == "front":
        print(dequeue._front())
    elif inputs[0] == "back":
        print(dequeue._back())