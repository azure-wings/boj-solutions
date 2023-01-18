#include <algorithm>
#include <iostream>

using namespace std;
int max_side;

struct Counter
{
    int first;
    int second;
    int third;

    inline Counter
    operator+(Counter a)
    {
        return { a.first + first, a.second + second, a.third + third };
    }
};

void
fast_io(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

Counter
count_squares(int** square, int n, pair<int, int> coords)
{
    if(n == 1)
    {
        Counter cnt;
        switch(square[coords.first][coords.second])
        {
        case -1:
            cnt = { 1, 0, 0 };
            break;
        case 0:
            cnt = { 0, 1, 0 };
            break;
        case 1:
            cnt = { 0, 0, 1 };
            break;
        }
        return cnt;
    }
    else
    {
        Counter sum = { 0, 0, 0 };
        int next_n  = int(n / 3);

        sum = count_squares(square, next_n, make_pair(coords.first, coords.second))
              + count_squares(
                  square, next_n, make_pair(coords.first + next_n, coords.second)
              )
              + count_squares(
                  square, next_n, make_pair(coords.first + 2 * next_n, coords.second)
              )
              + count_squares(
                  square, next_n, make_pair(coords.first, coords.second + next_n)
              )
              + count_squares(
                  square,
                  next_n,
                  make_pair(coords.first + next_n, coords.second + next_n)
              )
              + count_squares(
                  square,
                  next_n,
                  make_pair(coords.first + 2 * next_n, coords.second + next_n)
              )
              + count_squares(
                  square, next_n, make_pair(coords.first, coords.second + 2 * next_n)
              )
              + count_squares(
                  square,
                  next_n,
                  make_pair(coords.first + next_n, coords.second + 2 * next_n)
              )
              + count_squares(
                  square,
                  next_n,
                  make_pair(coords.first + 2 * next_n, coords.second + 2 * next_n)
              );

        if(sum.first == 9 && sum.second == 0 && sum.third == 0)
            sum = { 1, 0, 0 };
        else if(sum.first == 0 && sum.second == 9 && sum.third == 0)
            sum = { 0, 1, 0 };
        else if(sum.first == 0 && sum.second == 0 && sum.third == 9)
            sum = { 0, 0, 1 };

        return sum;
    }
}

int
main(void)
{
    fast_io();

    int max_side;
    int** square;
    Counter result = { 0, 0, 0 };

    cin >> max_side;

    square = new int*[max_side];

    for(int i = 0; i < max_side; i++)
    {
        square[i] = new int[max_side];
        for(int j = 0; j < max_side; j++)
        {
            cin >> square[i][j];
        }
    }

    result = count_squares(square, max_side, make_pair(0, 0));
    cout << result.first << "\n";
    cout << result.second << "\n";
    cout << result.third << "\n";

    return 0;
}