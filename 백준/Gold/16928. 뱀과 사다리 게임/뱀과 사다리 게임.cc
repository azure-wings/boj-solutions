#include <iostream>
#include <queue>

using namespace std;

struct board
{
    int grid[100] = { 0 };
};

void
fast_io(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

board
input_function(void)
{
    int num_ladders, num_snakes;
    board b;

    cin >> num_ladders;
    cin >> num_snakes;

    for(int i = 0; i < num_ladders; i++)
    {
        int from, to;
        cin >> from >> to;
        b.grid[from - 1] = to - 1;
    }

    for(int i = 0; i < num_snakes; i++)
    {
        int from, to;
        cin >> from >> to;
        b.grid[from - 1] = to - 1;
    }

    return b;
}

int
bfs(board b)
{
    queue<int> q;
    int count[100];

    fill_n(count, 100, 100);
    count[0] = 0;
    q.push(0);

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        for(int i = 1; i <= 6; i++)
        {
            int new_idx = curr + i;

            if(b.grid[new_idx])
                new_idx = b.grid[new_idx];

            if(count[new_idx] > count[curr] + 1)
            {
                count[new_idx] = count[curr] + 1;
                q.push(new_idx);
            }
            if(new_idx == 99)
                return count[99];
        }
    }
    return -1;
}

int
main(void)
{
    fast_io();

    board b = input_function();

    cout << bfs(b) << endl;
    return 0;
}