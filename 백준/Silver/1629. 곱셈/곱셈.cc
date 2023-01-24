#include <iostream>

using namespace std;

void
fast_io(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

long long
power_with_div_conquer(long long base, long long exp, long long mod)
{
    if(exp == 0)
        return 1;
    else if(exp == 1)
        return base % mod;

    long long result = power_with_div_conquer(base, exp / 2, mod) % mod;
    if(exp % 2 == 0)
        return (result * result) % mod;
    else if(exp % 2 == 1)
        return (((result * result) % mod) * base) % mod;
    else
        throw "Unexpected behaviour\n";
}

int
main(void)
{
    fast_io();

    long long base, exp, mod;

    cin >> base >> exp >> mod;
    cout << power_with_div_conquer(base, exp, mod) << endl;

    return 0;
}