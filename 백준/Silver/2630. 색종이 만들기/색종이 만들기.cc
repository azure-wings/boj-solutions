#include <algorithm>
#include <iostream>

using namespace std;
int max_side;

template <typename T, typename U>
std::pair<T, U>
operator+(const std::pair<T, U>& l, const std::pair<T, U>& r)
{
    return { l.first + r.first, l.second + r.second };
}

inline int
log_2(int n)
{
    int result = 0;
    while(n != 1)
    {
        n >>= 1;
        result++;
    }
    return result;
}

pair<int, int>
count_squares(int** square, int n, pair<int, int> coords)
{
    if(n == 1)
    {
        if(square[coords.first][coords.second] == 1)
            return make_pair(0, 1);
        else
            return make_pair(1, 0);
    }
    else
    {
        pair<int, int> sum;
        sum = count_squares(square, n >> 1, make_pair(coords.first, coords.second))
              + count_squares(
                  square, n >> 1, make_pair(coords.first + (n >> 1), coords.second)
              )
              + count_squares(
                  square, n >> 1, make_pair(coords.first, coords.second + (n >> 1))
              )
              + count_squares(
                  square,
                  n >> 1,
                  make_pair(coords.first + (n >> 1), coords.second + (n >> 1))
              );
        if(sum.first == 0 && sum.second == 4)
            return make_pair(0, 1);
        else if(sum.first == 4 && sum.second == 0)
            return make_pair(1, 0);
        else
            return sum;
    }
}

int
main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int** square;
    pair<int, int> result;

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

    return 0;
}