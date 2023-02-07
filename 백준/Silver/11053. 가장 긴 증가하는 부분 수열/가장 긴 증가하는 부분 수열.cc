#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int>
input_function(void)
{
    int n;
    vector<int> v;

    cin >> n;
    while(n--)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }

    return v;
}

int
lis(const vector<int>& seq)
{
    vector<int> dp;

    for(int i = 0; i < seq.size(); i++)
    {
        auto iter = lower_bound(dp.begin(), dp.end(), seq[i]);

        if(iter == dp.end())
            dp.push_back(seq[i]);
        else
            *iter = seq[i];
    }
    return dp.size();
}
int
main()
{
    vector<int> seq = input_function();
    cout << lis(seq) << '\n';
    return 0;
}
