#include <algorithm>
#include <iostream>

using namespace std;

int
main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases, num_elem;
    int* inputs;
    long long* sequence;

    cin >> test_cases;
    inputs = new int[test_cases];
    for(int i = 0; i < test_cases; i++)
        cin >> inputs[i];

    num_elem = *max_element(inputs, inputs + test_cases);
    sequence = new long long[num_elem + 1];

    sequence[1] = 1;
    sequence[2] = 1;
    sequence[3] = 1;

    for(int i = 4; i < num_elem + 1; i++)
    {
        sequence[i] = sequence[i - 2] + sequence[i - 3];
    }

    for(int i = 0; i < test_cases; i++)
    {
        cout << sequence[inputs[i]] << "\n";
    }

    return 0;
}