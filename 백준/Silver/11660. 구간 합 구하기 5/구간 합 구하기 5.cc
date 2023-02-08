#include <iostream>
#include <vector>

using namespace std;

struct numbers
{
    int n;
    int m;
    int** nums;
    pair<pair<int, int>, pair<int, int> >* coords;
};

void
fast_io(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

numbers
input_function(void)
{
    numbers n;
    cin >> n.n >> n.m;

    n.nums   = new int*[n.n];
    n.coords = new pair<pair<int, int>, pair<int, int> >[n.m];
    for(int i = 0; i < n.n; i++)
    {
        int sum   = 0;
        n.nums[i] = new int[n.n];
        for(int j = 0; j < n.n; j++)
        {
            int tmp;
            cin >> tmp;
            sum += tmp;
            n.nums[i][j] = sum;
        }
    }

    for(int i = 0; i < n.m; i++)
    {
        pair<int, int> c1, c2;
        cin >> c1.first >> c1.second >> c2.first >> c2.second;
        n.coords[i] = { c1, c2 };
    }

    return n;
};

vector<int>
find_sum(numbers n)
{
    vector<int> results;

    for(int i = 0; i < n.m; i++)
    {
        auto [x1, y1] = n.coords[i].first;
        auto [x2, y2] = n.coords[i].second;
        int sum       = 0;

        for(int k = (x1 - 1); k < x2; k++)
        {
            if(y1 >= 2)
                sum += (n.nums[k][y2 - 1] - n.nums[k][y1 - 2]);
            else
                sum += n.nums[k][y2 - 1];
        }

        results.push_back(sum);
    }

    return results;
}

int
main()
{
    fast_io();

    numbers n           = input_function();
    vector<int> results = find_sum(n);

    for(auto r : results)
        cout << r << '\n';

    return 0;
}
