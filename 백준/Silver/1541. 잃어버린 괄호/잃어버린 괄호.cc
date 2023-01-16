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
find_minimum(string& s)
{
    bool subtract = false;
    int result    = 0;
    string num    = "";

    for(int i = 0; i <= s.length(); i++)
    {
        if(i == s.length())
        {
            return subtract ? result - stoi(num) : result + stoi(num);
        }

        switch(s[i])
        {
        case '-':
        case '+':
            result = subtract ? result - stoi(num) : result + stoi(num);
            subtract |= (s[i] == '-');
            num = "";
            break;

        default:
            num += s[i];
        }
    }
}

int
main(void)
{
    fast_io();
    string input;

    cin >> input;
    cout << find_minimum(input) << endl;

    return 0;
}