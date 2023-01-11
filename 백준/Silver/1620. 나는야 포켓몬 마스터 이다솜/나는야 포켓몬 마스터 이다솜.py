from typing import List, Dict
import sys

def sol_1620(pokemons: List[str]) -> Dict[str, str]:
    pokedex = dict()
    for i, p in enumerate(pokemons):
        pokedex[str(i+1)] = p
        pokedex[p] = i+1
    return pokedex

if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    pokemons = [None] * n
    for i in range(n):
        pokemons[i] = sys.stdin.readline().rstrip()
    pokedex = sol_1620(pokemons)
    for i in range(m):
        print(pokedex[sys.stdin.readline().rstrip()])