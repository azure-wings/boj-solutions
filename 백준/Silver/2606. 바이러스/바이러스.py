from typing import List
from collections import deque
import sys

class Graph():
    def __init__(self, n: int):
        self.nodes = [ set() for _ in range(n+1) ]
        
    def add_edge(self, v1: int, v2: int):
        self.nodes[v1].add(v2)
        self.nodes[v2].add(v1)
        
    def count_connected(self, v: int) -> int:
        connected_nodes = set([v])
        dq = deque([v])

        while dq:
            curr = dq.pop()
            connected_nodes.add(curr)
            curr_conn = self.nodes[curr]
            for adj in curr_conn:
                if adj not in connected_nodes:
                    dq.append(adj)
            connected_nodes |= set(curr_conn)

        connected_nodes.remove(v)
        return len(connected_nodes)
    
if __name__ == "__main__":
    n = int(sys.stdin.readline())
    m = int(sys.stdin.readline())
    graph = Graph(n)
    for _ in range(m):
        v1, v2 = map(int, sys.stdin.readline().split())
        graph.add_edge(v1, v2)
    print(graph.count_connected(1))