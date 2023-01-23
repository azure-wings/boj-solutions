#include <algorithm>
#include <iostream>
#include <string.h>


using namespace std;

struct rgb_street
{
    int num_houses;
    int* red;
    int* green;
    int* blue;
};

void
fast_io(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

rgb_street
input_function(void)
{
    rgb_street s;

    cin >> s.num_houses;
    s.red   = new int[s.num_houses];
    s.green = new int[s.num_houses];
    s.blue  = new int[s.num_houses];

    for(int i = 0; i < s.num_houses; i++)
        cin >> s.red[i] >> s.green[i] >> s.blue[i];

    return s;
}

int
find_min_price(rgb_street s)
{
    int cache[3][s.num_houses];

    memset(cache, -1, sizeof(cache));
    cache[0][0] = s.red[0];
    cache[1][0] = s.green[0];
    cache[2][0] = s.blue[0];

    for(int i = 1; i < s.num_houses; i++)
    {
        cache[0][i] = min(cache[1][i - 1], cache[2][i - 1]) + s.red[i];
        cache[1][i] = min(cache[0][i - 1], cache[2][i - 1]) + s.green[i];
        cache[2][i] = min(cache[0][i - 1], cache[1][i - 1]) + s.blue[i];
    }

    return min({ cache[0][s.num_houses - 1],
                 cache[1][s.num_houses - 1],
                 cache[2][s.num_houses - 1] });
}

int
main(void)
{
    fast_io();

    rgb_street s = input_function();

    cout << find_min_price(s) << endl;

    return 0;
}