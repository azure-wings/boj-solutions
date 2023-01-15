#include <iostream>

using namespace std;

int
find_visit_order(int n, int r, int c)
{
    if(n == 1)
    {
        return 2 * r + c;
    }
    else
    {
        int quad, offset;
        quad   = 2 * int(r / (1 << (n - 1))) + int(c / (1 << (n - 1)));
        offset = (1 << (2 * n - 2)) * quad;
        switch(quad)
        {
        case 0:
            return offset + find_visit_order(n - 1, r, c);
        case 1:
            return offset + find_visit_order(n - 1, r, c - (1 << (n - 1)));
        case 2:
            return offset + find_visit_order(n - 1, r - (1 << (n - 1)), c);
        case 3:
            return offset
                   + find_visit_order(n - 1, r - (1 << (n - 1)), c - (1 << (n - 1)));
        }
    }
}

int
main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, c;
    cin >> n >> r >> c;
    cout << find_visit_order(n, r, c);

    return 0;
}