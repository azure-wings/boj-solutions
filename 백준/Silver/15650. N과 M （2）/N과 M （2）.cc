#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct picking
{
    int n;
    int m;
    vector<int> picked;
};

void
fast_io(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

picking
input_function(void)
{
    picking p;

    cin >> p.n >> p.m;
    return p;
}

void
print_vector(vector<int> v)
{
    for(auto n : v)
        cout << n << ' ';
    cout << endl;
}

void
dfs(picking &p)
{
    if(p.picked.size() == p.m)
    {
        print_vector(p.picked);
        return;
    } else
    {
        int smallest;

        smallest = p.picked.empty() ? 1 : p.picked.back() + 1;
        for(int next = smallest; next <= p.n; next++)
        {
            p.picked.push_back(next);
            dfs(p);
            p.picked.pop_back();
        }
    }
}

int
main(void)
{
    fast_io();

    picking p = input_function();
    dfs(p);

    return 0;
}