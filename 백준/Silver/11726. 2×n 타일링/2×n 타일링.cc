#include <iostream>
#include <queue>

using namespace std;

int
count_ways(int n)
{
    int memo[n + 1] = { 0 };

    memo[1] = 1;
    memo[2] = 2;
    for(int i = 3; i < n + 1; i++)
    {
        memo[i] = memo[i - 1] + memo[i - 2];
        memo[i] %= 10'007;
    }
    return memo[n];
}

int
main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;
    cout << count_ways(n) << "\n";

    return 0;
}