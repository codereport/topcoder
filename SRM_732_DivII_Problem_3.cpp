// code_report Solution
// https://youtu.be/OuiEk87IVQs

#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <limits>

using namespace std;

static const vector<int> dx = { 1 , 0 , -1 , 0 };
static const vector<int> dy = { 0 , 1 , 0 , -1 };

class TheFlippingGame2 {
public:

    int explore (int H, int W, const vector<string>& grid)
    {
        int min_flips = numeric_limits<int>::max ();
        vector<vector<int>> explored (H, vector<int> (W, -1));

        for (int sy = 0; sy < H; ++sy) {
            for (int sx = 0; sx < W; ++sx)
            {
                for (auto& row : explored) fill (row.begin (), row.end (), -1);
                priority_queue<pair<int, pair<int, int>>> q;
                int max_flips = 0;

                explored[sy][sx] = 0;
                q.push ({ 0 ,{ sy, sx } });

                while (!q.empty ())
                {
                    int cf = -q.top ().first;
                    int cy =  q.top ().second.first;
                    int cx =  q.top ().second.second;
                    q.pop ();

                    max_flips = max (max_flips, cf);

                    for (int i = 0; i < 4; ++i)
                    {
                        int ny = cy + dy[i];
                        int nx = cx + dx[i];
                        if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;

                        if (explored[ny][nx] == -1)
                        {
                            explored[ny][nx] = cf + (grid[cy][cx] != grid[ny][nx]);
                            q.push ({ -explored[ny][nx],{ ny, nx } });
                        }
                    }
                }

                min_flips = min (min_flips, max_flips);
            }
        }

        return min_flips;
    }

    int MinimumMoves (int n, int m, vector<string> x)
    {
        int min_flips = numeric_limits<int>::max ();

        for (auto color : {'b', 'w'})
        {
            vector<string> filled_grid = x;
            for (auto& row : filled_grid) replace (row.begin (), row.end (), 'e', color);

            min_flips = min (min_flips, explore (n, m, filled_grid));
        }

        return min_flips + 1; // special turn counts
    }
};
