#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct calculator
{
    int reg_a;
    int reg_b;

    inline int
    calculate(int n, int option)
    {
        switch(option)
        {
        case 0:
            return 2 * n % 10000;
        case 1:
            return n ? n - 1 : 9999;
        case 2:
            return (n % 1000) * 10 + int(n / 1000);
        case 3:
            return int(n / 10) + 1000 * (n % 10);
        default:
            return -1;
        }
    }
};

void
fast_io(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

queue<calculator>
input_function(void)
{
    int num_queries;
    queue<calculator> q;
    cin >> num_queries;

    for(int i = 0; i < num_queries; i++)
    {
        calculator c;
        cin >> c.reg_a >> c.reg_b;
        q.push(c);
    }

    return q;
}

string
bfs(calculator c)
{
    auto [from, to] = c;
    queue<pair<int, string> > visiting;
    char op_to_char[4]  = { 'D', 'S', 'L', 'R' };
    bool visited[10000] = { 0 };

    visiting.push({ from, "" });
    visited[from] = true;

    while(!visiting.empty())
    {
        auto [curr_num, curr_str] = visiting.front();
        visiting.pop();

        for(int i = 0; i < 4; i++)
        {
            int next_num    = c.calculate(curr_num, i);
            string next_str = curr_str + op_to_char[i];

            if(next_num == to)
                return next_str;

            if(visited[next_num])
                continue;

            visited[next_num] = true;
            visiting.push({ next_num, next_str });
        }
    }
    return "";
}

int
main(void)
{
    fast_io();

    queue<calculator> q = input_function();

    while(!q.empty())
    {
        cout << bfs(q.front()) << '\n';
        q.pop();
    }

    return 0;
}