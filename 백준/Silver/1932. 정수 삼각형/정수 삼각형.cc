#include <iostream>

using namespace std;

struct triangle
{
    int size;
    int** nums;
};

void
fast_io(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

triangle
input_function(void)
{
    triangle t;
    cin >> t.size;

    t.nums = new int*[t.size];
    for(int i = 0; i < t.size; i++)
    {
        t.nums[i] = new int[t.size];
        for(int j = 0; j < t.size; j++)
            if(j <= i)
                cin >> t.nums[i][j];
            else
                t.nums[i][j] = 0;
    }

    return t;
}

int
find_max_sum(triangle t)
{
    int** memo;
    int max_sum = 0;

    memo = new int*[t.size];
    for(int i = 0; i < t.size; i++)
    {
        memo[i] = new int[t.size];
        for(int j = 0; j < t.size; j++)
            memo[i][j] = 0;
    }

    memo[0][0] = t.nums[0][0];
    for(int i = 1; i < t.size; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == 0)
                memo[i][j] = memo[i - 1][j] + t.nums[i][j];
            else
                memo[i][j] = max(
                    memo[i - 1][j - 1] + t.nums[i][j], memo[i - 1][j] + t.nums[i][j]
                );
        }
    }

    for(int i = 0; i < t.size; i++)
        max_sum = max(max_sum, memo[t.size - 1][i]);
    
    return max_sum;
}

int
main()
{
    fast_io();

    triangle t = input_function();

    cout << find_max_sum(t) << '\n';

    return 0;
}