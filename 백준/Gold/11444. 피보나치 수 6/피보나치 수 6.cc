#include <cstring>
#include <functional>
#include <iostream>
#include <map>

using namespace std;
using ull = unsigned long long;

void
fast_io(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ull
fibonacci(ull x, ull r)
{
    map<ull, ull> memo = { { 0, 0 }, { 1, 1 }, { 2, 1 } };

    function<ull(ull)> dOcgane = [&](ull n) -> ull {
        if(memo.count(n) > 0)
            return memo[n];
        else
        {
            ull k = (n % 2 == 0 ? n / 2 : (n + 1) / 2);
            ull f_k_minus_1, f_k;
            f_k_minus_1 = dOcgane(k - 1);
            f_k         = dOcgane(k);
            switch(n % 2)
            {
            case 0:
                memo[n] = ((2ULL * f_k_minus_1 + f_k)) * f_k;
                break;
            case 1:
                memo[n] = (f_k * f_k) + (f_k_minus_1 * f_k_minus_1);
                break;
            }

            memo[n] %= r;
            return memo[n];
        }
    };

    return dOcgane(x);
}

int
main()
{
    fast_io();

    ull n;
    cin >> n;
    cout << fibonacci(n, 1000000007ULL) << '\n';

    return 0;
}