#include <algorithm>
#include <iostream>
#include <numeric>
#define INF 999'999

using namespace std;

void
floyd_warshall(int** relations, int n)
{
    for(int k = 1; k < n + 1; k++)
    {
        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < n + 1; j++)
            {
                if((relations[i][k] != INF) && (relations[k][j] != INF))
                {
                    if(relations[i][j] == INF)
                        relations[i][j] = relations[i][k] + relations[k][j];
                    else
                        relations[i][j] = min(
                            relations[i][j], relations[i][k] + relations[k][j]
                        );
                }
            }
        }
    }
}

int
main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num_users, num_relations, user1, user2, min_max, index;
    int** relations;

    cin >> num_users >> num_relations;
    relations = new int*[num_users + 1];
    for(int i = 0; i < num_users + 1; i++)
    {
        relations[i] = new int[num_users + 1];
        for(int j = 0; j < num_users + 1; j++)
            relations[i][j] = INF;
        relations[i][i] = 0;
    }

    for(int i = 0; i < num_relations; i++)
    {
        cin >> user1 >> user2;
        relations[user1][user2] = 1;
        relations[user2][user1] = 1;
    }

    floyd_warshall(relations, num_users);

    min_max = INF;
    for(int i = 1; i < num_users + 1; i++)
    {
        int sum = 0;
        for(int j = 1; j < num_users + 1; j++)
            sum += relations[i][j];
        if(sum < min_max)
        {
            min_max = sum;
            index   = i;
        }
    }

    cout << index << "\n";
    return 0;
}