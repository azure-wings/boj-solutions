#include <iostream>
#include <queue>
#include <string.h>
#define INF (1 << 30)

using namespace std;

void
fast_io(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

class Aquarium
{
  private:
    int** school;
    int** visited;
    int aquarium_size;
    pair<int, int> shark_loc;
    int shark_size  = 2;
    int shark_eaten = 0;

  public:
    inline bool
    coord_in_range(pair<int, int> loc)
    {
        return (
            0 <= loc.first && loc.first < aquarium_size && 0 <= loc.second
            && loc.second < aquarium_size
        );
    }

    inline bool
    compare_locations(pair<int, int> a, pair<int, int> b)
    {
        return (a.first < b.first || (a.first == b.first && a.second < b.second));
    }

    void
    set_shark_loc(pair<int, int> loc)
    {
        shark_loc = loc;
    }

    void
    reset_visited(void)
    {
        for(int j = 0; j < aquarium_size; j++)
        {
            memset(visited[j], 0, sizeof(int) * aquarium_size);
        }
    }

    int
    get_visited(pair<int, int> loc)
    {
        if(loc == make_pair(INF, INF))
            return INF;
        else
            return visited[loc.first][loc.second];
    }

    void
    set_visited(pair<int, int> loc, int num)
    {
        visited[loc.first][loc.second] = num;
    }

    void init_school(void);
    void eat_fish(pair<int, int> loc);
    int bfs(void);
};

void
Aquarium::init_school(void)
{
    int input;

    cin >> aquarium_size;

    school  = new int*[aquarium_size];
    visited = new int*[aquarium_size];
    for(int i = 0; i < aquarium_size; i++)
    {
        school[i]  = new int[aquarium_size];
        visited[i] = new int[aquarium_size];
        for(int j = 0; j < aquarium_size; j++)
        {
            cin >> input;
            switch(input)
            {
            case 9:
                set_shark_loc({ i, j });
                school[i][j] = 0;
                break;
            default:
                school[i][j] = input;
                break;
            }
            visited[i][j] = 0;
        }
    }
}

void
Aquarium::eat_fish(pair<int, int> loc)
{
    school[loc.first][loc.second] = 0;
    shark_eaten++;
    if(shark_size == shark_eaten)
    {
        shark_eaten = 0;
        shark_size++;
    }
}

int
Aquarium::bfs()
{
    queue<pair<int, int> > visiting;
    pair<int, int> destination = { INF, INF };
    int d_row[4]               = { -1, 0, 1, 0 };
    int d_col[4]               = { 0, -1, 0, 1 };

    visiting.push(shark_loc);
    while(!visiting.empty())
    {
        auto [curr_row, curr_col] = visiting.front();

        visiting.pop();

        for(int i = 0; i < 4; i++)
        {
            int next_row = curr_row + d_row[i];
            int next_col = curr_col + d_col[i];

            if(!coord_in_range({ next_row, next_col })
               || visited[next_row][next_col] > 0)
                continue;

            if(0 < school[next_row][next_col]
               && school[next_row][next_col] < shark_size)
            {
                set_visited({ next_row, next_col }, visited[curr_row][curr_col] + 1);

                if(get_visited({ next_row, next_col }) < get_visited(destination))
                {
                    destination = { next_row, next_col };
                }
                else if(get_visited({ next_row, next_col }) == get_visited(destination))
                {
                    destination
                        = compare_locations(destination, { next_row, next_col })
                              ? destination
                              : make_pair(next_row, next_col);
                }
                visited[next_row][next_col] = visited[curr_row][curr_col] + 1;
            }
            else if(school[next_row][next_col] > shark_size)
                continue;
            else
            {
                visiting.push({ next_row, next_col });
                visited[next_row][next_col] = visited[curr_row][curr_col] + 1;
            }
        }
    }

    if(destination != make_pair(INF, INF))
    {
        set_shark_loc(destination);
        eat_fish(destination);

        int time = visited[destination.first][destination.second];
        reset_visited();

        return time;
    }

    return -1;
}

int
main(void)
{
    fast_io();

    Aquarium a           = Aquarium();
    int total_time       = 0;
    int next_travel_time = 0;

    a.init_school();

    while(true)
    {
        next_travel_time = a.bfs();
        if(next_travel_time < 0)
            break;
        else
            total_time += next_travel_time;
    }

    cout << total_time << endl;

    return 0;
}