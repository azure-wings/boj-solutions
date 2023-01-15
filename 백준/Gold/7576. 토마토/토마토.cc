#include <iostream>
#include <queue>

using namespace std;

struct tomatos
{
    int** conditions;
    int width;
    int height;
};

void
bfs(tomatos& t, queue<pair<int, int> > q)
{
    int curr_x, curr_y, next_x, next_y;
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };

    while(!q.empty())
    {
        curr_x = q.front().first;
        curr_y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            next_x = curr_x + dx[i];
            next_y = curr_y + dy[i];
            if(next_x < 0 || next_x >= t.width || next_y < 0 || next_y >= t.height)
                continue;
            switch(t.conditions[next_y][next_x])
            {
            case -1:
                continue;
            case 0:
                t.conditions[next_y][next_x] = t.conditions[curr_y][curr_x] + 1;
                q.push({ next_x, next_y });
                break;
            }
        }
    }
}

int
count_days(tomatos t)
{
    int max = 0;
    for(int i = 0; i < t.height; i++)
    {
        for(int j = 0; j < t.width; j++)
        {
            if(t.conditions[i][j] == 0)
                return -1;
            if(t.conditions[i][j] > max)
                max = t.conditions[i][j];
        }
    }
    return max - 1;
}

int
main(void)
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    tomatos t;
    queue<pair<int, int> > q;
    int m, n;

    cin >> m >> n;
    t.conditions = new int*[m * n];
    t.height     = n;
    t.width      = m;
    for(int i = 0; i < n; i++)
    {
        t.conditions[i] = new int[m];
        for(int j = 0; j < m; j++)
        {
            cin >> t.conditions[i][j];
            if(t.conditions[i][j] == 1)
            {
                q.push({ j, i });
            }
        }
    }
    bfs(t, q);
    cout << count_days(t) << "\n";

    return 0;
}