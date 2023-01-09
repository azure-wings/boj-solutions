from __future__ import annotations
import sys

class Editor():
    def __init__(self, s: List[str]):
        self.l_stack = s
        self.r_stack = []
        
    def move_left(self):
        try:
            left_top = self.l_stack.pop()
            self.r_stack.append(left_top)
        except:
            pass
        
    def move_right(self):
        try:
            right_top = self.r_stack.pop()
            self.l_stack.append(right_top)
        except:
            pass
        
    def delete(self):
        try:
            self.l_stack.pop()
        except:
            pass
            
    def add_left(self, c: str):
        self.l_stack.append(c)
        
string = sys.stdin.readline().rstrip()
editor = Editor(list(string))
n = int(sys.stdin.readline())
for i in range(n):
    inputs = sys.stdin.readline().split()
    if inputs[0] == "L":
        editor.move_left()
    elif inputs[0] == "D":
        editor.move_right()
    elif inputs[0] == "B":
        editor.delete()
    elif inputs[0] == "P":
        editor.add_left(inputs[1])

print(''.join(editor.l_stack + editor.r_stack[::-1]))