import sys
from dataclasses import dataclass, field
from numbers import Number
from typing import List


@dataclass
class Edge:
    src: int
    dst: int
    cost: int


@dataclass
class Graph:
    vertices: int = 0
    edges: List[Edge] = field(default_factory=list)


def input_function() -> Graph:
    graph: Graph = Graph()
    graph.vertices, roads, wormholes = map(int, sys.stdin.readline().split())
    graph.edges = [None] * (2 * roads + wormholes)
    i: int = 0

    for _ in range(roads):
        src, dst, cost = map(int, sys.stdin.readline().split())
        graph.edges[i] = Edge(src, dst, cost)
        graph.edges[i + 1] = Edge(dst, src, cost)
        i += 2

    for _ in range(wormholes):
        src, dst, cost = map(int, sys.stdin.readline().split())
        graph.edges[i] = Edge(src, dst, -1 * cost)
        i += 1

    return graph


def bellman_ford(graph: Graph) -> bool:
    visited: List[bool] = [False] * (graph.vertices + 1)

    for i in range(1, graph.vertices + 1):
        if visited[i]:
            continue

        dist: List[Number] = [float("inf")] * (graph.vertices + 1)
        dist[i] = 0
        visited[i] = True
        for _ in range(1, graph.vertices):
            for e in graph.edges:
                if dist[e.src] < float("inf") and dist[e.src] + e.cost < dist[e.dst]:
                    dist[e.dst] = dist[e.src] + e.cost
                    visited[e.dst] = True

        for e in graph.edges:
            if dist[e.src] < float("inf") and dist[e.src] + e.cost < dist[e.dst]:
                return True

    return False


if __name__ == "__main__":
    t: int = int(sys.stdin.readline())
    yes, no = "YES", "NO"

    for _ in range(t):
        graph: Graph = input_function()
        print(f"{yes if bellman_ford(graph) else no}")
