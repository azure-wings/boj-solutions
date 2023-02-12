import sys
from typing import List, Tuple

def knapsack(
    weights: List[int],
    values: List[int],
    capacity: int,
    num_items: int
) -> int:
    """Find the maximum of sum of values among all possible combinations of items
    Args:
        weights (List[int]): List of weights of each item
        values (List[int]): List of values of each item
        capacity (int): Weight capacity of the knapsack
        num_items (int): Number of items being considered
    Return:
        max_value (int): Maximum of sum of values
    """
    memo = [[0 for _ in range(capacity + 1)] for _ in range(num_items + 1)]

    for i in range(1, num_items + 1):
        for j in range(1, capacity + 1):
            if weights[i-1] > j:
                memo[i][j] = memo[i-1][j]
            else:
                memo[i][j] = max(
                    values[i-1] + memo[i-1][j - weights[i-1]],
                    memo[i-1][j]
                )

    max_value = memo[-1][-1]
    return max_value


if __name__ == "__main__":
    num_items, capacity = map(int, sys.stdin.readline().split())
    
    weights, values = [None] * num_items, [None] * num_items
    for i in range(num_items):
        weights[i], values[i] = map(int, sys.stdin.readline().split())

    print(knapsack(weights, values, capacity, num_items))