#include <cstring>
#include <iostream>

using namespace std;

void
fast_io(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int
count_ways(int n)
{
    int memo[n + 1];
    memset(memo, 0, sizeof(memo));

    memo[1] = 1;
    memo[2] = 3;
    for(int i = 3; i < n + 1; i++)
    {
        memo[i] = memo[i - 1] + 2 * memo[i - 2];
        memo[i] %= 10'007;
    }
    return memo[n];
}

int
main(void)
{
    fast_io();

    int n;

    cin >> n;
    cout << count_ways(n) << "\n";

    return 0;
}