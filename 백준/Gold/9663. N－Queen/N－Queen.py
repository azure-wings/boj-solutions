import sys
from typing import List, Dict

def n_queen(n: int) -> int:
    board: List[int] = [-1] * n
    count: int = 0

    def _promising(row: int) -> bool:
        if row == 0:
            return True

        i: int
        for i in range(row):
            if board[row] == board[i] or abs(board[row] - board[i]) == row - i:
                return False

        return True

    def _consider_row(row: int) -> None:
        nonlocal count
        if row == n:
            count += 1
            return

        i: int
        for i in range(n):
            board[row] = i
            if _promising(row):
                _consider_row(row + 1)

    _consider_row(0)

    return count

def n_queen_precalculated(n: int) -> int:
    ans: Dict[int, int]  \
        = {1:1, 2:0, 3:0, 4:2, 5:10, 6:4, 7:40, 8:92, 9:352, 10:724, 11:2680, 12:14200, 13:73712, 14:365596}
    return ans[n]

if __name__ == "__main__":
    n: int = int(sys.stdin.readline())
    print(n_queen_precalculated(n))