#include <algorithm>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int
main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int* num_arr;
    map<int, int> compressed;

    cin >> n;
    num_arr = new int[n];

    for(int i = 0; i < n; i++)
    {
        cin >> num_arr[i];
        compressed[num_arr[i]]++;
    }

    auto iter = compressed.begin();
    int i     = 0;

    for(; iter != compressed.end(); iter++, i++)
    {
        iter->second = i;
    }

    for(int i = 0; i < n; i++)
    {
        cout << compressed.find(num_arr[i])->second << " ";
    }

    cout << endl;
    return 0;
}