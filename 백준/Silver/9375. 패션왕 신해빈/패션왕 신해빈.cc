#include <iostream>
#include <map>
#include <string>

using namespace std;

int
main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases, garments, result;
    string input;

    cin >> test_cases;
    for(int i = 0; i < test_cases; i++)
    {
        map<string, int> counts;

        cin >> garments;
        for(int j = 0; j < garments; j++)
        {
            cin >> input;
            cin >> input;
            auto found = counts.find(input);
            if(found == counts.end())
                counts.insert({ input, 1 });
            else
                found->second++;
        }
        result = 1;
        for(auto iter = counts.begin(); iter != counts.end(); iter++)
        {
            result *= (iter->second + 1);
        }

        cout << result - 1 << "\n";
    }

    return 0;
}