#include <iostream>
#define INF 999999

using namespace std;

struct graph
{
    int** matrix;
    int nodes;
};

void
fast_io(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void
floyd_warshall(graph g)
{
    for(int k = 0; k < g.nodes; k++)
    {
        for(int i = 0; i < g.nodes; i++)
        {
            for(int j = 0; j < g.nodes; j++)
            {
                g.matrix[i][j]
                    = min(g.matrix[i][j], g.matrix[i][k] + g.matrix[k][j]);
            }
        }
    }
}

int
main(void)
{
    fast_io();

    graph g;
    int input;

    cin >> input;
    g.nodes = input;

    g.matrix = new int*[g.nodes];
    for(int i = 0; i < g.nodes; i++)
    {
        g.matrix[i] = new int[g.nodes];
        for(int j = 0; j < g.nodes; j++)
        {
            cin >> input;
            if(input == 0)
                g.matrix[i][j] = INF;
            else
                g.matrix[i][j] = input;
        }
    }

    floyd_warshall(g);

    for(int i = 0; i < g.nodes; i++)
    {
        for(int j = 0; j < g.nodes; j++)
        {
            if(g.matrix[i][j] < INF)
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << '\n';
    }
}