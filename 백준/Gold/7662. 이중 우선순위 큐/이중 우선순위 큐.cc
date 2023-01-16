#include <iostream>
#include <set>

using namespace std;

void
double_pq(int k)
{
    char cmd;
    int target;
    multiset<int> ms;

    for(int i = 0; i < k; i++)
    {
        cin >> cmd >> target;
        switch(cmd)
        {
        case 'I':
            ms.insert(target);
            break;
        case 'D':
            switch(target)
            {
            case 1:
                if(!ms.empty())
                    ms.erase(ms.find(*ms.rbegin()));
                break;
            case -1:
                if(!ms.empty())
                    ms.erase(ms.find(*ms.begin()));
                break;
            }
            break;
        }
    }
    if(ms.empty())
        cout << "EMPTY" << endl;
    else
        cout << *ms.rbegin() << " " << *ms.begin() << endl;
}

int
main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> k;
        double_pq(k);
    }

    return 0;
}