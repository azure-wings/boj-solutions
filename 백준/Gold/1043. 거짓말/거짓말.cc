#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct liar
{
    int num_people;
    int num_party;
    vector<int> knows_truth;
    int *node_parents;
};

void
fast_io(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

liar
input_function(void)
{
    liar l;
    int num_truth;

    cin >> l.num_people >> l.num_party;

    l.node_parents = new int[l.num_people + 1];
    for(int i = 0; i <= l.num_people; i++)
        l.node_parents[i] = i;

    cin >> num_truth;
    for(int i = 0; i < num_truth; i++)
    {
        int temp;
        cin >> temp;
        l.knows_truth.push_back(temp);
    }

    return l;
}

int
find_root(liar l, int n)
{
    if(l.node_parents[n] == n)
        return n;

    return find_root(l, l.node_parents[n]);
}

void
union_root(liar &l, int n, int m)
{
    int root_n, root_m;
    root_n = find_root(l, n);
    root_m = find_root(l, m);

    if(root_n != root_m)
    {
        if(find(l.knows_truth.begin(), l.knows_truth.end(), root_m)
           != l.knows_truth.end())
        {
            int target = l.node_parents[n];
            for(int i = 0; i < l.num_people + 1; i++)
            {
                if(l.node_parents[i] == target)
                    l.node_parents[i] = root_m;
            }
        } else
        {
            int target = l.node_parents[m];
            for(int i = 0; i < l.num_people + 1; i++)
            {
                if(l.node_parents[i] == target)
                    l.node_parents[i] = root_n;
            }
        }
    }
}

int
main(void)
{
    fast_io();
    liar l = input_function();
    vector<vector<int> > parties;
    int num_can_lie = 0;

    for(int i = 0; i < l.num_party; i++)
    {
        int num_participants, representative;
        vector<int> party;
        
        cin >> num_participants;
        cin >> representative;
        party.push_back(representative);
        if(num_participants > 1)
        {
            for(int j = 1; j < num_participants; j++)
            {
                int temp;
                cin >> temp;
                party.push_back(temp);
            }
        }
        parties.push_back(party);
    }

    for(auto p : parties)
    {
        for(int i = 1; i < p.size(); i++)
        {
            union_root(l, p[0], p[i]);
        }
    }

    for(int i = 0; i < l.num_party; i++)
    {
        bool check = true;
        for(int j : l.knows_truth)
        {
            if(find_root(l, parties[i].front()) == find_root(l, j))
            {
                check = false;
                break;
            }
        }
        if(check)
            num_can_lie++;
    }

    cout << num_can_lie << endl;

    return 0;
}