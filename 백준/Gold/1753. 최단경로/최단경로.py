import sys
from typing import List, Tuple
from heapq import heappush, heappop

INF: int = 1e8
INFSTR: str = "INF"

def dijkstra(graph: List[List[int]], start: int) -> List[int]:
    distances: List[int] = [INF for _ in range(len(graph))]
    visiting: List[Tuple[int, int]] = []
    
    heappush(visiting, (0, start))
    distances[start] = 0

    while visiting:
        curr_cost: int; curr_node: int
        curr_cost, curr_node = heappop(visiting)

        if distances[curr_node] < curr_cost:
            continue
        else:
            for next_cost_node_pair in graph[curr_node]:
                if curr_cost + next_cost_node_pair[0] < distances[next_cost_node_pair[1]]:
                    distances[next_cost_node_pair[1]] = curr_cost + next_cost_node_pair[0]
                    heappush(visiting, (curr_cost + next_cost_node_pair[0], next_cost_node_pair[1]))

    return distances

if __name__ == "__main__":
    v: int; e: int
    v, e = map(int, sys.stdin.readline().split())
    start: int = int(sys.stdin.readline().rstrip())

    graph: List[List[Tuple[int, int]]] = [[] for _ in range(v+1)]

    for _ in range(e):
        v1: int; v2: int; cost: int
        v1, v2, cost = map(int, sys.stdin.readline().split())
        graph[v1].append((cost, v2))

    distances: List[int] = dijkstra(graph, start)
    for i in range(1, len(distances)):
        print(f"{distances[i] if distances[i] < INF else INFSTR}")