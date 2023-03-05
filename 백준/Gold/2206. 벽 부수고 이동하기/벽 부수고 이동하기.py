import sys
from collections import deque
from typing import Tuple, List, Deque


def input_function() -> List[List[int]]:
    n, m = map(int, sys.stdin.readline().split())
    matrix: List[List[int]] = [[] for _ in range(n)]

    for i in range(n):
        matrix[i] = [int(i) for i in sys.stdin.readline().rstrip()]

    return matrix


def bfs(matrix: List[List[int]]) -> int:
    n, m = len(matrix), len(matrix[0])
    visited: List[List[List[int]]] = [[[0] * m for _ in range(n)] for _ in range(2)]
    visiting: Deque[Tuple[int, int, int]] = deque()
    dx: List[int] = [1, 0, -1, 0]
    dy: List[int] = [0, 1, 0, -1]

    visiting.append((0, 0, 0))
    visited[0][0][0] = 1
    visited[1][0][0] = 1

    while visiting:
        broken, curr_y, curr_x = visiting.popleft()
        if curr_y == n - 1 and curr_x == m - 1:
            return visited[broken][curr_y][curr_x]

        for i in range(4):
            next_y: int = curr_y + dy[i]
            next_x: int = curr_x + dx[i]

            if not (0 <= next_y < n and 0 <= next_x < m):
                continue

            if broken == 1:
                if matrix[next_y][next_x] == 0 and visited[1][next_y][next_x] == 0:
                    visited[1][next_y][next_x] = visited[1][curr_y][curr_x] + 1
                    visiting.append((1, next_y, next_x))
            else:
                if matrix[next_y][next_x] == 1 and visited[1][next_y][next_x] == 0:
                    visited[1][next_y][next_x] = visited[0][curr_y][curr_x] + 1
                    visiting.append((1, next_y, next_x))
                elif matrix[next_y][next_x] == 0 and visited[0][next_y][next_x] == 0:
                    visited[0][next_y][next_x] = visited[0][curr_y][curr_x] + 1
                    visiting.append((0, next_y, next_x))

    else:
        return -1


if __name__ == "__main__":
    matrix: List[List[int]] = input_function()
    print(bfs(matrix))
