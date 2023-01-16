#include <iostream>
#define INF 999'999

using namespace std;

int
main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, queries, lo_idx, hi_idx;
    int *numbers, *sums;

    cin >> n >> queries;
    numbers = new int[n + 1];
    sums    = new int[n + 1];

    numbers[0] = 0;
    sums[0]    = 0;

    for(int i = 1; i <= n; i++)
    {
        cin >> numbers[i];
        sums[i] = numbers[i] + sums[i - 1];
    }

    for(int i = 0; i < queries; i++)
    {
        cin >> lo_idx >> hi_idx;
        cout << sums[hi_idx] - sums[lo_idx - 1] << "\n";
    }

    return 0;
}