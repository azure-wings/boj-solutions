#include <cassert>
#include <iostream>
#include <queue>
#define INF (1 << 30)

using namespace std;

struct graph
{
    int num_people;
    int num_roads;
    int target;
    vector<pair<int, int> >* roads;
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
    cin >> g.num_people >> g.num_roads >> g.target;

    g.roads = new vector<pair<int, int> >[g.num_people + 1];

    for(int i = 0; i < g.num_roads; i++)
    {
        int from, to, takes;
        cin >> from >> to >> takes;

        g.roads[from].push_back({ to, takes });
    }

    return g;
}

vector<int>
dijkstra(graph g, int start)
{
    vector<int> min_times(g.num_people + 1, INF);
    priority_queue<pair<int, int> > visiting;

    min_times[start] = 0;
    visiting.push({ start, 0 });

    while(!visiting.empty())
    {
        int curr_node = visiting.top().first;
        int curr_time = -visiting.top().second;
        visiting.pop();

        for(auto next : g.roads[curr_node])
        {
            auto [next_node, next_time] = next;
            next_time += curr_time;

            if(next_time < min_times[next_node])
            {
                min_times[next_node] = next_time;
                visiting.push({ next_node, -next_time });
            }
        }
    }

    return min_times;
}

int
find_max(vector<int> v1, vector<int> v2)
{
    pair<int, int> max = { -1, -1 };

    assert(v1.size() == v2.size());

    for(int i = 1; i < v1.size(); i++)
    {
        if(max.second < (v1[i] + v2[i]) && (v1[i] + v2[i]) < INF)
            max = { i, (v1[i] + v2[i]) };
    }

    return max.second;
}

int
main(void)
{
    fast_io();

    graph g = input_function();

    vector<int> min_gather, min_split;

    min_gather.push_back(INF);
    for(int i = 1; i <= g.num_people; i++)
        min_gather.push_back(dijkstra(g, i)[g.target]);

    min_split = dijkstra(g, g.target);

    cout << find_max(min_gather, min_split) << endl;

    return 0;
}