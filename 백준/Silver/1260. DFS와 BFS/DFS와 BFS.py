from typing import List
from collections import deque
import sys

class smart_dict(dict):
    @staticmethod
    def __missing__(key):
        return [key]

class Graph():
    def __init__(self):
        self.nodes = smart_dict()
        
    def add_edge(self, v1: int, v2: int):
        if v1 in self.nodes:
            self.nodes[v1].add(v2)
        else:
            self.nodes[v1] = {v2}
        if v2 in self.nodes:
            self.nodes[v2].add(v1)
        else:
            self.nodes[v2] = {v1}

    def dfs(self, v: int) -> List[int]:
        dq = deque([v])
        result = []
        while dq:
            curr = dq.pop()
            if curr not in result:
                result.append(curr)
                dq.extend(sorted(list(self.nodes[curr]), reverse=True))
        return result
    
    def bfs(self, v: int) -> List[int]:
        dq = deque([v])
        result = []
        while dq:
            curr = dq.pop()
            if curr not in result:
                result.append(curr)
                dq.extendleft(sorted(list(self.nodes[curr])))
        return result
    
if __name__ == "__main__":
    n, m, v = map(int, sys.stdin.readline().split())
    graph = Graph()
    for _ in range(m):
        v1, v2 = map(int, sys.stdin.readline().split())
        graph.add_edge(v1, v2)
    print(*graph.dfs(v))
    print(*graph.bfs(v))