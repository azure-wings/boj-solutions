#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void
fast_io(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

string
quad_tree(int** square, int n, pair<int, int> coords)
{
    if(n == 1)
    {
        switch(square[coords.first][coords.second])
        {
        case 0:
            return "0";
        case 1:
            return "1";
        }
    }
    else
    {
        string result = "";
        int next_n    = n >> 1;

        result = "("
                 + quad_tree(square, next_n, make_pair(coords.first, coords.second))
                 + quad_tree(
                     square, next_n, make_pair(coords.first, coords.second + next_n)
                 )
                 + quad_tree(
                     square, next_n, make_pair(coords.first + next_n, coords.second)
                 )
                 + quad_tree(
                     square,
                     next_n,
                     make_pair(coords.first + next_n, coords.second + next_n)
                 )
                 + ")";

        if(result == "(0000)")
            return "0";
        else if(result == "(1111)")
            return "1";
        else
            return result;
    }
}

int
main(void)
{
    fast_io();

    int max_side;
    int** square;
    char input;
    string result = "";

    cin >> max_side;
    cin.ignore();

    square = new int*[max_side];

    for(int i = 0; i < max_side; i++)
    {
        square[i] = new int[max_side];
        for(int j = 0; j <= max_side; j++)
        {
            input = cin.get();
            if(j == max_side)
                continue;
            square[i][j] = input - '0';
        }
    }

    result = quad_tree(square, max_side, make_pair(0, 0));
    cout << result << "\n";

    return 0;
}