#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

struct tomatos
{
    int*** conditions;
    int width;
    int length;
    int height;
};

bool
in_range(tomatos t, int x, int y, int z)
{
    return !(
        x < 0 || x >= t.width || y < 0 || y >= t.length || z < 0 || z >= t.height
    );
}

void
bfs(tomatos& t, queue<tuple<int, int, int> > q)
{
    int curr_x, curr_y, curr_z, next_x, next_y, next_z;
    int dx[6] = { -1, 1, 0, 0, 0, 0 };
    int dy[6] = { 0, 0, -1, 1, 0, 0 };
    int dz[6] = { 0, 0, 0, 0, -1, 1 };

    while(!q.empty())
    {
        curr_x = get<0>(q.front());
        curr_y = get<1>(q.front());
        curr_z = get<2>(q.front());
        q.pop();
        for(int i = 0; i < 6; i++)
        {
            next_x = curr_x + dx[i];
            next_y = curr_y + dy[i];
            next_z = curr_z + dz[i];
            if(!in_range(t, next_x, next_y, next_z))
                continue;
            switch(t.conditions[next_z][next_y][next_x])
            {
            case -1:
                continue;
            case 0:
                t.conditions[next_z][next_y][next_x]
                    = t.conditions[curr_z][curr_y][curr_x] + 1;
                q.push(make_tuple(next_x, next_y, next_z));
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
        for(int j = 0; j < t.length; j++)
        {
            for(int k = 0; k < t.width; k++)
            {
                if(t.conditions[i][j][k] == 0)
                    return -1;
                if(t.conditions[i][j][k] > max)
                    max = t.conditions[i][j][k];
            }
        }
    }
    return max - 1;
}

int
main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    tomatos t;
    queue<tuple<int, int, int> > q;
    int m, n, h;

    cin >> m >> n >> h;
    t.conditions = new int**[h];
    t.height     = h;
    t.length     = n;
    t.width      = m;

    for(int i = 0; i < h; i++)
    {
        t.conditions[i] = new int*[n];
        for(int j = 0; j < n; j++)
        {
            t.conditions[i][j] = new int[m];
            for(int k = 0; k < m; k++)
            {
                cin >> t.conditions[i][j][k];
                if(t.conditions[i][j][k] == 1)
                {
                    q.push(make_tuple(k, j, i));
                }
            }
        }
    }
    bfs(t, q);
    cout << count_days(t) << "\n";

    return 0;
}