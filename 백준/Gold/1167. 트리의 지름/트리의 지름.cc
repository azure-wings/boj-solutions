#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <vector>

using namespace std;

struct graph
{
    int num_nodes;
    vector<pair<int, int> >* matrix;
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

    cin >> g.num_nodes;
    g.matrix = new vector<pair<int, int> >[g.num_nodes + 1];

    for(int i = 1; i <= g.num_nodes; i++)
    {
        int node, input1, input2;
        cin >> node;
        while(true)
        {
            cin >> input1;
            if(input1 == -1)
                break;
            else
            {
                cin >> input2;
                g.matrix[node].push_back({ input1, input2 });
            }
        }
    }

    return g;
}

pair<int, int>
dfs(graph g, int node)
{
    stack<pair<int, int> > visiting;
    set<int> visited;
    pair<int, int> farthest_node_and_dist = { 0, 0 };

    visited.insert(node);
    visiting.push({ node, 0 });

    do
    {
        auto [curr_node, curr_dist] = visiting.top();

        visiting.pop();
        visited.insert(curr_node);

        for(auto iter = g.matrix[curr_node].begin();
            iter != g.matrix[curr_node].end();
            iter++)
        {
            if(visited.find(iter->first) == visited.end())
            {
                visiting.push({ iter->first, iter->second + curr_dist });

                if(iter->second + curr_dist > farthest_node_and_dist.second)
                    farthest_node_and_dist
                        = { iter->first, iter->second + curr_dist };
            }
        }

    } while(!visiting.empty());

    return farthest_node_and_dist;
}

int
find_tree_diameter(graph g)
{
    pair<int, int> farthest_node_and_dist;

    farthest_node_and_dist = dfs(g, 1);
    farthest_node_and_dist = dfs(g, farthest_node_and_dist.first);

    return farthest_node_and_dist.second;
}

int
main(void)
{
    fast_io();

    graph g = input_function();

    cout << find_tree_diameter(g) << endl;

    return 0;
}