#include <cstring>
#include <iostream>
#define INF 999999

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
    int square_sum[n + 1];
    memset(square_sum, INF, sizeof(square_sum));

    square_sum[0] = 1;
    square_sum[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j * j <= i; j++)
        {
            if(j * j == i)
                square_sum[i] = 1;
            else
                square_sum[i] = min(square_sum[i], square_sum[i - j * j] + 1);
        }
    }
    return square_sum[n];
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