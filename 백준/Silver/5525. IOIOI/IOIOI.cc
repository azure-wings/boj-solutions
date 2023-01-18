#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

void
fast_io(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int
count_query(char* given, int n)
{
    int count = 0;
    char query[2 * (n + 1)];

    query[0] = 'I';
    for(int i = 1; i <= n; i++)
    {
        query[2 * i - 1] = 'O';
        query[2 * i]     = 'I';
    }
    query[2 * n + 1] = '\0';

    while(given = strstr(given + 1, query))
        count++;

    return count;
}

int
main(void)
{
    fast_io();

    int n, m;
    char* given;

    cin >> n;
    cin >> m;
    given = new char[m + 1];

    cin.ignore();
    cin.getline(given, m + 1, '\n');

    cout << count_query(given, n) << "\n";

    return 0;
}