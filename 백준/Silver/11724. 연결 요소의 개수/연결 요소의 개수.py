from typing import Set
from collections import deque
import sys

class Graph():
    def __init__(self, n: int):
        self.nodes = [set() for _ in range(n+1)]
        self.edges = 0
        
    def add_edge(self, v1: int, v2: int):
        self.nodes[v1].add(v2)
        self.nodes[v2].add(v1)
        self.edges += 1
    
    def dfs(self, v: int) -> Set[int]:
        dq = deque([v])
        result = set()
        while dq:
            curr = dq.pop()
            if curr not in result:
                result.add(curr)
                dq.extend(list(self.nodes[curr]))
        return result

    def count_connected(self) -> int:
        count = 0
        connected = set()
        for i in range(len(self.nodes)):
            if i == 0 or i in connected:
                continue
            connected.add(i)
            connected |= self.dfs(i)
            count += 1
        return count
    
if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    graph = Graph(n)
    for _ in range(m):
        v1, v2 = map(int, sys.stdin.readline().split())
        graph.add_edge(v1, v2)
    print(graph.count_connected())