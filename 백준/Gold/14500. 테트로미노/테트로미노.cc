#include <array>
#include <iostream>

using namespace std;

struct board
{
    int rows;
    int cols;
    int **grid;

    inline bool
    in_range(pair<int, int> coords, pair<int, int> ofs)
    {
        return (
            0 <= (coords.first + ofs.first) && (coords.first + ofs.first) < rows
            && 0 <= (coords.second + ofs.second)
            && (coords.second + ofs.second) < cols
        );
    }

    inline int
    get_idx_elem(pair<int, int> coords, pair<int, int> ofs)
    {
        return grid[coords.first + ofs.first][coords.second + ofs.second];
    }
};

void
fast_io(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

board
input_function(void)
{
    board b;
    cin >> b.rows >> b.cols;

    b.grid = new int *[b.rows];
    for(int i = 0; i < b.rows; i++)
    {
        b.grid[i] = new int[b.cols];
        for(int j = 0; j < b.cols; j++)
        {
            cin >> b.grid[i][j];
        }
    }

    return b;
}

int
find_max(board b)
{
    pair<int, int> tetrominos[19][4]
        = { // Square
            { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } },
            // Straight
            { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 } },
            { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 } },
            // T-shaped
            { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 1 } },
            { { 0, 0 }, { 0, 1 }, { 0, 2 }, { -1, 1 } },
            { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 1, 1 } },
            { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 1, -1 } },
            // L-shaped
            { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 2 } },
            { { 0, 0 }, { 0, 1 }, { 0, 2 }, { -1, 2 } },
            { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 2, 1 } },
            { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 2, -1 } },
            { { 0, 0 }, { 1, 0 }, { 0, 1 }, { 0, 2 } },
            { { 0, 0 }, { -1, 0 }, { 0, 1 }, { 0, 2 } },
            { { 0, 0 }, { 0, -1 }, { 1, 0 }, { 2, 0 } },
            { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 2, 0 } },
            // Skewed
            { { 0, 0 }, { 0, 1 }, { -1, 1 }, { -1, 2 } },
            { { 0, 0 }, { 0, 1 }, { 1, 1 }, { 1, 2 } },
            { { 0, 0 }, { 0, 1 }, { -1, 1 }, { 1, 0 } },
            { { 0, 0 }, { 0, 1 }, { -1, 0 }, { 1, 1 } }
          };
    int max = 0;

    for(int i = 0; i < b.rows; i++)
    {
        for(int j = 0; j < b.cols; j++)
        {
            for(int t = 0; t < 19; t++)
            {
                int sum = 0;
                for(int s = 0; s < 4; s++)
                {
                    auto idx = tetrominos[t][s];
                    if(!b.in_range({ i, j }, idx))
                        break;
                    else
                        sum += b.get_idx_elem({ i, j }, idx);
                }
                max = max < sum ? sum : max;
            }
        }
    }

    return max;
}

int
main(void)
{
    fast_io();

    board b = input_function();
    cout << find_max(b) << endl;

    return 0;
}