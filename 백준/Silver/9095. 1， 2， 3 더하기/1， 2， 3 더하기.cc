#include <algorithm>
#include <iostream>

using namespace std;

int
count_ways(int n)
{
    int memo[n + 1] = { 0 };

    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;
    for(int i = 4; i < n + 1; i++)
    {
        memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
    }
    return memo[n];
}

int
main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, input;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> input;
        cout << count_ways(input) << "\n";
    }

    return 0;
}