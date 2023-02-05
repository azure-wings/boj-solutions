#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct picking
{
    int n;
    int m;
    vector<int> picked;
    int* nums;
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
    p.nums = new int[p.n];

    for(int i = 0; i < p.n; i++)
        cin >> p.nums[i];

    sort(p.nums, p.nums + p.n);
    return p;
}

void
print_vector(vector<int> v)
{
    for(auto n : v)
        cout << n << ' ';
    cout << '\n';
}

void
dfs(picking& p)
{
    if(p.picked.size() == p.m)
    {
        print_vector(p.picked);
        return;
    }
    else
    {
        for(int i = 0; i < p.n; i++)
        {
            if(p.picked.empty() || p.nums[i] >= p.picked.back())
            {
                p.picked.push_back(p.nums[i]);
                dfs(p);
                p.picked.pop_back();
            }
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