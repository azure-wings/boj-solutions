from __future__ import annotations
import sys

def sol_11650(coords: List[Tuple[int, int]]) -> List[Tuple[int, int]]:
    coords = sorted(coords, key=lambda x: (x[0], x[1]))
    return coords

n = int(sys.stdin.readline())
coords = []
for i in range(n):
    x, y = map(int, sys.stdin.readline().split())
    coords.append((x, y))
coords = sol_11650(coords)
for coord in coords:
    print(coord[0], coord[1])