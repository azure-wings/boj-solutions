#include <iostream>
#include <queue>

using namespace std;

void
fast_io(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void
abs_heap(int commands)
{
    priority_queue<int> neg;
    priority_queue<int, vector<int>, greater<int> > pos;
    int input;

    for(int i = 0; i < commands; i++)
    {
        cin >> input;
        switch(input)
        {
        case 0:
            if(pos.empty() && neg.empty())
                cout << 0 << '\n';
            else
            {
                if(pos.empty())
                {
                    cout << neg.top() << '\n';
                    neg.pop();
                }
                else if(neg.empty())
                {
                    cout << pos.top() << '\n';
                    pos.pop();
                }
                else
                {
                    if(-1 * neg.top() <= pos.top())
                    {
                        cout << neg.top() << '\n';
                        neg.pop();
                    }
                    else
                    {
                        cout << pos.top() << '\n';
                        pos.pop();
                    }
                }
            }
            break;
        default:
            if(input > 0)
                pos.push(input);
            else
                neg.push(input);
        }
    }
}

int
main(void)
{
    fast_io();

    int commands;

    cin >> commands;
    abs_heap(commands);
}