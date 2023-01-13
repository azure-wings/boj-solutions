from collections import deque
import sys

class Grid():
    def __init__(self, m: int, n: int):
        self.grid = [[0 for _ in range(m)] for _ in range(n)]
    
    def add_cabbage(self, x: int, y: int):
        self.grid[y][x] = 1
        
    def find_connected(self, x: int, y: int):
        visiting = deque([(y, x)])
        m, n = len(self.grid[0]), len(self.grid)
        while visiting:
            curr_y, curr_x = visiting.pop()
            if 0 <= curr_x < m and \
                0 <= curr_y < n and \
                self.grid[curr_y][curr_x] == 1:
                    self.grid[curr_y][curr_x] = 0
                    visiting.extend([
                        (curr_y, curr_x - 1),
                        (curr_y, curr_x + 1),
                        (curr_y - 1, curr_x),
                        (curr_y + 1, curr_x)
                    ])
            else:
                continue
    
    def sol_1012(self):
        count = 0
        for y in range(len(self.grid)):
            for x in range(len(self.grid[0])):
                if self.grid[y][x] == 1:
                    self.find_connected(x, y)
                    count += 1
        return count
    
if __name__ == "__main__":
    t = int(sys.stdin.readline())
    for _ in range(t):
        m, n, k = map(int, sys.stdin.readline().split())
        grid = Grid(m, n)
        for _ in range(k):
            x, y = map(int, sys.stdin.readline().split())
            grid.add_cabbage(x, y)
        print(grid.sol_1012())