#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

void
fast_io(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

class Maze
{
  private:
    pair<int, int> target;
    int** square;

  public:
    Maze(void) {}
    Maze(pair<int, int> target) { this->target = target; }
    ~Maze(void) {}

    void init_maze(void);
    bool in_range(pair<int, int> coord);
    int find_min_move(void);
};

void
Maze::init_maze()
{
    char input;

    square = new int*[target.first + 1];
    for(int i = 0; i < target.first + 1; i++)
    {
        square[i] = new int[target.second + 1];
        for(int j = 0; j <= target.second + 1; j++)
        {
            input = cin.get();
            if(j == target.second + 1)
                continue;
            square[i][j] = input - '0';
        }
    }
}

bool
Maze::in_range(pair<int, int> coord)
{
    return (
        0 <= coord.first && coord.first <= target.first && 0 <= coord.second
        && coord.second <= target.second
    );
}

int
Maze::find_min_move(void)
{
    queue<pair<int, int> > q;
    int d_row[4] = { -1, +1, 0, 0 };
    int d_col[4] = { 0, 0, -1, +1 };
    int curr_row, curr_col, next_row, next_col;

    q.push({ 0, 0 });

    while(!q.empty())
    {
        curr_row = q.front().first;
        curr_col = q.front().second;
        q.pop();

        if(!square[curr_row][curr_col])
            continue;
        else
        {
            for(int i = 0; i < 4; i++)
            {
                next_row = curr_row + d_row[i];
                next_col = curr_col + d_col[i];
                if(!in_range({ next_row, next_col }))
                    continue;

                switch(square[next_row][next_col])
                {
                case 1:
                    square[next_row][next_col] = square[curr_row][curr_col] + 1;
                    q.push({ next_row, next_col });
                    break;
                default:
                    continue;
                }
            }
        }
    }
    return square[target.first][target.second];
}

int
main(void)
{
    fast_io();

    int target_row, target_col;

    cin >> target_row >> target_col;
    cin.ignore();

    Maze maze({ target_row - 1, target_col - 1 });
    maze.init_maze();

    cout << maze.find_min_move() << "\n";

    return 0;
}