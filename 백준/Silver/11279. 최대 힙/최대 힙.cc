#include <iostream>
#include <queue>

using namespace std;

void
max_heap(int n)
{
    int input;
    priority_queue<int> pq;

    for(int i = 0; i < n; i++)
    {
        cin >> input;
        switch(input)
        {
        case 0:
            if(!pq.empty())
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
            else
                cout << "0\n";
            break;

        default:
            pq.push(input);
        }
    }
}

int
main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n;
    max_heap(n);

    return 0;
}