import sys
from collections import deque
from typing import Tuple, Dict, List, Deque

INF: int = 10_000_000


def input_function() -> Tuple[Dict[int, List[Tuple[int, int]]], int]:
    tree: Dict[int, int] = dict()
    total: int = int(sys.stdin.readline())

    for _ in range(total - 1):
        parent, child, cost = map(int, sys.stdin.readline().split())
        if parent not in tree:
            tree[parent] = [(child, cost)]
        else:
            tree[parent].append((child, cost))
        if child not in tree:
            tree[child] = [(parent, cost)]
        else:
            tree[child].append((parent, cost))

    return tree, total


def dfs(tree: Dict[int, List[Tuple[int, int]]], start: int, total: int) -> Tuple[int, int]:
    dist_memo: List[int] = [INF] * (total + 1)
    visited: List[bool] = [False] * (total + 1)
    visiting: Deque[int] = deque()

    visiting.append(start)
    dist_memo[start] = 0

    while visiting:
        curr_node = visiting.popleft()
        if visited[curr_node]:
            continue
        visited[curr_node] = True

        for next_node, next_dist in tree[curr_node]:
            visiting.append(next_node)
            dist_memo[next_node] = min(dist_memo[curr_node] + next_dist, dist_memo[next_node])

    max_node: int = 0
    max_dist: int = 0
    for i in range(1, total + 1):
        if max_dist < dist_memo[i] < 1e7:
            max_node = i
            max_dist = dist_memo[i]

    return max_node, max_dist


def find_tree_diameter(tree: Dict[int, List[Tuple[int, int]]], total: int) -> int:
    max_node: int
    max_dist: int
    max_node, max_dist = dfs(tree, 1, total)
    return dfs(tree, max_node, total)[1]


if __name__ == "__main__":
    tree: Dict[int, List[Tuple[int, int]]]
    total: int
    tree, total = input_function()
    if total == 1:
        print(0)
    else:
        print(find_tree_diameter(tree, total))
