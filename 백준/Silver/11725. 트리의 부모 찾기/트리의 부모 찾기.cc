#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct tree
{
    int num_nodes;
    map<int, vector<int> > nodes;
    int* parents;
};

void
fast_io(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void
insert_edge(map<int, vector<int> >& g, int node_1, int node_2)
{
    auto iter_1 = g.find(node_1);
    auto iter_2 = g.find(node_2);

    if(iter_1 != g.end())
        iter_1->second.push_back(node_2);
    else
    {
        vector<int> v = { node_2 };
        g.insert({ node_1, v });
    }

    if(iter_2 != g.end())
        iter_2->second.push_back(node_1);
    else
    {
        vector<int> v = { node_1 };
        g.insert({ node_2, v });
    }
}

tree
input_function(void)
{
    tree t;
    cin >> t.num_nodes;

    t.parents = new int[t.num_nodes + 1];
    memset(t.parents, 0, sizeof(int) * (t.num_nodes + 1));

    for(int i = 1; i < t.num_nodes; i++)
    {
        int node_1, node_2;
        cin >> node_1 >> node_2;
        insert_edge(t.nodes, node_1, node_2);
    }

    return t;
}

void
bfs(tree t)
{
    queue<int> visiting;
    bool visited[t.num_nodes + 1];

    memset(visited, false, sizeof(visited));

    visiting.push(1);
    visited[1] = true;

    while(!visiting.empty())
    {
        int curr_node = visiting.front();
        visiting.pop();
        visited[curr_node] = true;

        auto adjacents = t.nodes.find(curr_node)->second;
        for(auto next : adjacents)
        {
            if(visited[next])
                continue;

            visiting.push(next);

            if(t.parents[next] != 0)
                continue;
            else
                t.parents[next] = curr_node;
        }
    }
}

int
main()
{
    fast_io();

    tree t = input_function();
    bfs(t);

    for(int i = 2; i <= t.num_nodes; i++)
        cout << t.parents[i] << '\n';

    return 0;
}
