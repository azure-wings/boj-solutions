#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

struct graph
{
    char** matrix;
    int side;

    inline bool
    in_range(pair<int, int> coords)
    {
        return (
            0 <= coords.first && coords.first < side && 0 <= coords.second
            && coords.second < side
        );
    }
};

void
fast_io(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

tuple<graph, graph, graph>
input_function(void)
{
    graph g, will_visit_normal, will_visit_daltonian;
    int input;

    cin >> input;
    g.side                    = input;
    will_visit_normal.side    = input;
    will_visit_daltonian.side = input;
    cin.ignore();

    g.matrix                    = new char*[g.side];
    will_visit_normal.matrix    = new char*[will_visit_normal.side];
    will_visit_daltonian.matrix = new char*[will_visit_daltonian.side];

    for(int i = 0; i < g.side; i++)
    {
        g.matrix[i]                    = new char[g.side];
        will_visit_normal.matrix[i]    = new char[will_visit_normal.side];
        will_visit_daltonian.matrix[i] = new char[will_visit_daltonian.side];
        for(int j = 0; j < g.side; j++)
        {
            g.matrix[i][j]                    = cin.get();
            will_visit_normal.matrix[i][j]    = true;
            will_visit_daltonian.matrix[i][j] = true;
        }

        cin.get(); // Ignore newline character
    }

    return { g, will_visit_normal, will_visit_daltonian };
}

void
normal_bfs(graph g, graph& will_visit, pair<int, int> start_coord)
{
    queue<pair<int, int> > visiting;

    int d_row[4] = { -1, 1, 0, 0 };
    int d_col[4] = { 0, 0, -1, 1 };

    visiting.push(start_coord);

    while(!visiting.empty())
    {
        auto [row, col]  = visiting.front();
        char curr_colour = g.matrix[row][col];
        visiting.pop();

        for(int i = 0; i < 4; i++)
        {
            int n_row = row + d_row[i];
            int n_col = col + d_col[i];

            if(!g.in_range({ n_row, n_col }))
                continue;
            else if(!will_visit.matrix[n_row][n_col])
                continue;
            else
            {
                if(g.matrix[n_row][n_col] == curr_colour)
                {
                    will_visit.matrix[n_row][n_col] = false;
                    visiting.push({ n_row, n_col });
                }
            }
        }
    }
}

void
daltonian_bfs(graph g, graph& will_visit, pair<int, int> start_coord)
{
    queue<pair<int, int> > visiting;

    int d_row[4] = { -1, 1, 0, 0 };
    int d_col[4] = { 0, 0, -1, 1 };

    visiting.push(start_coord);

    while(!visiting.empty())
    {
        auto [row, col]  = visiting.front();
        char curr_colour = g.matrix[row][col];
        visiting.pop();

        for(int i = 0; i < 4; i++)
        {
            int n_row = row + d_row[i];
            int n_col = col + d_col[i];

            if(!g.in_range({ n_row, n_col }))
                continue;
            else if(!will_visit.matrix[n_row][n_col])
                continue;
            else
            {
                switch(curr_colour)
                {
                case 'B':
                    if(g.matrix[n_row][n_col] == 'B')
                    {
                        will_visit.matrix[n_row][n_col] = false;
                        visiting.push({ n_row, n_col });
                    }
                    break;
                default:
                    if(g.matrix[n_row][n_col] == 'R'
                       || g.matrix[n_row][n_col] == 'G')
                    {
                        will_visit.matrix[n_row][n_col] = false;
                        visiting.push({ n_row, n_col });
                    }
                    break;
                }
            }
        }
    }
}

int
main(void)
{
    fast_io();

    int normal    = 0;
    int daltonian = 0;

    auto [g, will_visit_normal, will_visit_daltonian] = input_function();

    for(int i = 0; i < g.side; i++)
    {
        for(int j = 0; j < g.side; j++)
        {
            if(will_visit_normal.matrix[i][j])
            {
                normal_bfs(g, will_visit_normal, { i, j });
                normal++;
            }
            if(will_visit_daltonian.matrix[i][j])
            {
                daltonian_bfs(g, will_visit_daltonian, { i, j });
                daltonian++;
            }
        }
    }

    cout << normal << ' ' << daltonian << endl;
    return 0;
}