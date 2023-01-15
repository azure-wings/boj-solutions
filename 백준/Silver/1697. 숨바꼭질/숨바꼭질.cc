#include <iostream>
#include <queue>
#define MAX_INDEX 100'001

using namespace std;

inline bool
in_range(int x)
{
    return (0 <= x and x < MAX_INDEX);
}

int
find_least_time(int n, int k)
{
    queue<pair<int, int> > q;
    int loc, time;
    bool visited[MAX_INDEX] = { false };

    q.push(make_pair(n, 0));
    visited[n] = true;

    while(!q.empty())
    {
        loc  = q.front().first;
        time = q.front().second;
        q.pop();

        if(loc == k)
            return time;

        if(in_range(loc - 1) && !visited[loc - 1])
        {
            visited[loc - 1] = true;
            q.push(make_pair(loc - 1, time + 1));
        }
        if(in_range(loc + 1) && !visited[loc + 1])
        {
            visited[loc + 1] = true;
            q.push(make_pair(loc + 1, time + 1));
        }
        if(in_range(2 * loc) && !visited[2 * loc])
        {
            visited[2 * loc] = true;
            q.push(make_pair(2 * loc, time + 1));
        }
    }

    return 0;
}

int
main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    cout << find_least_time(n, k);

    return 0;
}