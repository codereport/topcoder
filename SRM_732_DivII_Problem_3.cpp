// code_report Solution 
// 

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
	int explore (int H, int W, vector<string> grid) 
	{
		int min_flips = numeric_limits<int>::max ();
		
		for (int sy = 0; sy < H; ++sy) {
			for (int sx = 0; sx < W; ++sx) 
			{
				vector<vector<int>> done (H, vector<int> (W, -1));
				priority_queue<pair<int,pair<int,int>>> q;
				int max_flips = 0;

				done[sy][sx] = 0;
				q.push ({ 0 , { sy, sx } });

				while (q.size ()) 
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
						
						if (done[ny][nx] == -1) 
						{
							done[ny][nx] = cf + (grid[cy][cx] != grid[ny][nx]);
							q.push ({ -done[ny][nx], { ny, nx } });
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
		string colors = "wb";
		int min_flips = numeric_limits<int>::max ();

		for (auto color : colors) 
		{
			vector<string> filled_grid = x;
			
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j)
					if (x[i][j] == 'e') filled_grid[i][j] = color;

			min_flips = min (min_flips, explore (n, m, filled_grid));
		}

		return min_flips + 1; // special turn counts
	}
};
