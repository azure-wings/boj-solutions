from typing import List, Tuple
import sys

row = ("BWBWBWBW", "WBWBWBWB")
# boards = {
#     "bw": [ row[0] if i % 2 == 0 else row[1] for i in range(8) ],
#     "wb": [ row[1] if i % 2 == 0 else row[0] for i in range(8) ]
# }

def diff_btn_rows(s: str, target: int) -> int:
    diff = [ s[i] for i in range(8) if s[i] != row[target][i] ]
    return len(diff)

def diff_btn_boards(board: List[str]) -> int:
    diff_bw = sum(map(lambda x: diff_btn_rows(x[1], x[0] % 2), enumerate(board)))
    diff_wb = sum(map(lambda x: diff_btn_rows(x[1], 1 - x[0] % 2), enumerate(board)))
    return min(diff_bw, diff_wb)

def cut_board(i: int, j: int, big_board: List[str]) -> List[str]:
    return [ big_board[k][i:i+8] for k in range(j, j+8) ]

def sol_1018(big_board: List[str]) -> int:
    n, m = len(big_board), len(big_board[0])
    min_alter = n*m
    for i in range(m - 7):
        for j in range(n - 7):
            min_alter = min(min_alter, diff_btn_boards(cut_board(i, j, big_board)))
    return min_alter

if __name__ == "__main__":
    n, _ = map(int, sys.stdin.readline().split())
    big_board = [None] * n
    for i in range(n):
        big_board[i] = sys.stdin.readline().rstrip()
    print(sol_1018(big_board))