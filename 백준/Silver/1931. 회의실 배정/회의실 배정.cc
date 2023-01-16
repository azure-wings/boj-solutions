#include <algorithm>
#include <iostream>

using namespace std;

int
find_max_meetings(pair<int, int>* times, int n)
{
    int count, prev_end;

    sort(
        times,
        times + n,
        [](const pair<int, int>& pair1, const pair<int, int>& pair2) {
            return (
                (pair2.second > pair1.second)
                || ((pair2.second == pair1.second) && (pair2.first > pair1.first))
            );
        }
    );

    prev_end = times[0].second;
    count    = 1;

    for(int i = 1; i < n; i++)
    {
        if(times[i].first < prev_end)
        {
            continue;
        }
        else
        {
            prev_end = times[i].second;
            count++;
        }
    }

    return count;
}

int
main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, start, end;
    pair<int, int>* times;

    cin >> n;
    times = new pair<int, int>[n];

    for(int i = 0; i < n; i++)
    {
        cin >> start >> end;
        times[i] = make_pair(start, end);
    }

    cout << find_max_meetings(times, n) << "\n";

    return 0;
}