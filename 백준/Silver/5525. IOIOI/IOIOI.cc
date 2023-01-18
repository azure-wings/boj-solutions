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

int
count_query(string given, int n)
{
    int count = 0;
    string query;

    query = "I";
    for(int i = 0; i < n; i++)
        query += "OI";

    for(int i = 0; i < given.size() - n; i++)
    {
        if(given.substr(i, 2 * n + 1) == query)
            count++;
    }
    return count;
}

int
main(void)
{
    fast_io();

    int n, m;
    string given;

    cin >> n;
    cin >> m;
    cin.ignore();
    getline(cin, given);

    cout << count_query(given, n) << "\n";

    return 0;
}