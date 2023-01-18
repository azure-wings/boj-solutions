#include <algorithm>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

struct flat
{
    int** grid;
    int side;
};

void
fast_io(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

inline bool
in_range(flat block, pair<int, int> coords)
{
    return (
        0 <= coords.first && coords.first < block.side && 0 <= coords.second
        && coords.second < block.side
    );
}

int
dfs(flat block, pair<int, int> coords)
{
    queue<pair<int, int> > visiting;
    int d_row[4] = { -1, 1, 0, 0 };
    int d_col[4] = { 0, 0, -1, 1 };
    int count    = 1;
    visiting.push(coords);

    while(!visiting.empty())
    {
        int row = visiting.front().first;
        int col = visiting.front().second;
        visiting.pop();
        block.grid[row][col] = 0;

        for(int i = 0; i < 4; i++)
        {
            pair<int, int> next_coord = { row + d_row[i], col + d_col[i] };

            if(!in_range(block, next_coord))
                continue;
            if(block.grid[next_coord.first][next_coord.second] == 1)
            {
                block.grid[next_coord.first][next_coord.second] = 0;
                visiting.push(next_coord);
                count++;
            }
        }
    }
    return count;
}

int
main(void)
{
    fast_io();

    int num_estates = 0;
    char input;
    flat block;
    multiset<int> num_buildings;

    cin >> block.side;
    cin.ignore();

    block.grid = new int*[block.side];

    for(int i = 0; i < block.side; i++)
    {
        block.grid[i] = new int[block.side];
        for(int j = 0; j <= block.side; j++)
        {
            input = cin.get();
            if(j == block.side)
                continue;
            block.grid[i][j] = input - '0';
        }
    }

    for(int i = 0; i < block.side; i++)
    {
        for(int j = 0; j < block.side; j++)
        {
            if(block.grid[i][j] == 1)
            {
                num_buildings.insert(dfs(block, { i, j }));
                num_estates++;
            }
        }
    }

    cout << num_estates << "\n";
    for(auto iter = num_buildings.begin(); iter != num_buildings.end(); iter++)
        cout << *iter << "\n";

    return 0;
}