#include <iostream>
using namespace std;

int
gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int
lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int
cain_calendar(int m, int n, int x, int y)
{
    int max_year = lcm(m, n);
    int result   = -1;

    for(int i = x; i <= max_year; i += m)
    {
        int ny = i % n ? i % n : n;

        if(ny == y)
        {
            result = i;
            break;
        }
    }
    return result;
}

int
main()
{
    int test_cases;
    cin >> test_cases;

    for(int t = 0; t < test_cases; t++)
    {
        int m, n, x, y;

        cin >> m >> n >> x >> y;
        cout << cain_calendar(m, n, x, y) << '\n';
    }
    return 0;
}
