#include <iostream>
#define INF 10000001

using namespace std;

struct graph
{
    int **matrix;
    int nodes;
    int edges;
};

void
fast_io(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

graph
input_function(void)
{
    graph g;

    cin >> g.nodes;
    cin >> g.edges;
    g.matrix = new int *[g.nodes + 1];
    for(int i = 0; i < g.nodes + 1; i++)
    {
        g.matrix[i] = new int[g.nodes + 1];
        for(int j = 0; j < g.nodes + 1; j++)
        {
            g.matrix[i][j] = INF;
        }
    }

    for(int i = 0; i < g.edges; i++)
    {
        int from, to, takes;
        cin >> from >> to >> takes;
        if(g.matrix[from][to] > takes)
            g.matrix[from][to] = takes;
    }

    return g;
}

void
floyd_warshall(graph g)
{
    for(int k = 1; k < g.nodes + 1; k++)
    {
        for(int i = 1; i < g.nodes + 1; i++)
        {
            for(int j = 1; j < g.nodes + 1; j++)
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

    graph g = input_function();
    int input;

    floyd_warshall(g);

    for(int i = 1; i < g.nodes + 1; i++)
    {
        for(int j = 1; j < g.nodes + 1; j++)
        {
            if(i == j || g.matrix[i][j] == INF)
                cout << "0 ";
            else
                cout << g.matrix[i][j] << ' ';
        }
        cout << '\n';
    }
}