#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

struct picking
{
    int n;
    int m;
    vector<int> picked;
    int* nums;
    bool* taken;
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
    p.nums  = new int[p.n];
    p.taken = new bool[p.n];

    for(int i = 0; i < p.n; i++)
    {
        cin >> p.nums[i];
        p.taken[i] = false;
    }

    sort(p.nums, p.nums + p.n);
    return p;
}

void
dfs(picking& p, unordered_set<string>& s)
{
    if(p.picked.size() == p.m)
    {
        string str = "";
        for(int i = 0; i < p.picked.size(); i++)
            str += to_string(p.picked[i]) + " ";

        if(s.find(str) == s.end())
        {
            s.insert(str);
            cout << str << '\n';
        }
    }
    else
    {
        for(int i = 0; i < p.n; i++)
        {
            if(p.picked.empty() || p.nums[i] >= p.picked.back())
            {
                p.picked.push_back(p.nums[i]);
                dfs(p, s);
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
    unordered_set<string> s;

    dfs(p, s);

    return 0;
}