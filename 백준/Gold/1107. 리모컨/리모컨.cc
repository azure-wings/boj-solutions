#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>
#define MAX_CHN 999'999

using namespace std;

int
count_digits(int number, bool intact_keys[10])
{
    int digits = 0;

    do
    {
        if(!intact_keys[number % 10])
            return 0;
        number /= 10;
        digits++;
    } while(number != 0);

    return digits;
}

int
min_presses(int target, bool intact_keys[10])
{
    int min = INT_MAX;
    for(int i = 0; i < MAX_CHN; i++)
    {
        int counts, digits;
        counts = abs(target - i);
        digits = count_digits(i, intact_keys);
        if(!digits)
            continue;
        else
            min = min > counts + digits ? counts + digits : min;
    }
    return min > abs(target - 100) ? abs(target - 100) : min;
}

int
main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int target, num_broken, broken;
    bool intact_keys[10];
    fill_n(intact_keys, 10, true);

    cin >> target;
    cin >> num_broken;

    if(target == 100)
    {
        cout << 0 << "\n";
        return 0;
    }

    for(int i = 0; i < num_broken; i++)
    {
        cin >> broken;
        intact_keys[broken] = false;
    }

    cout << min_presses(target, intact_keys) << "\n";

    return 0;
}