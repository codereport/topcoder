// code_report Solution
// https://youtu.be/zwYi5y8GJu4

#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define FORI(s,n) for(int i = s; i < n; i++)
#define FORJ(s,n) for(int j = s; j < n; j++)

using vi  = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vvp = vector<vector<pii>>;

class TheSquareCityDiv2
{
public:

   int n;

   pii find_max (int x, int y, int r, const vvi& g) 
   {
      int max_ = 0;
      pii p;
      FORI (max (0, x - r), min (n, x + r + 1)) {
         FORJ (max (0, y - r), min (n, y + r + 1)) {
            if (abs (x - i) + abs (y - j) <= r) {
               if (g[i][j] > max_) {
                  max_ = g[i][j];
                  p = { i, j };
               }
            }
         }
      }

      return p;
   }

   vvi initialize_grid (const vi& t)
   {
      vvi grid (n, vi (n));

      FORI (0, n) {
         FORJ (0, n) {
            grid[i][j] = t[i*n + j];
         }
      }

      return grid;
   }

   vvp initialize_moves (int r, const vvi& grid)
   {
      vvp moves (n, vector<pii> (n));

      FORI (0, n) {
         FORJ (0, n) {
            moves[i][j] = find_max (i, j, r, grid);
         }
      }

      return moves;
   }

   vvi initialize_final_pos (const vvp& moves)
   {
      vvi grid (n, vi (n));

      FORI (0, n) {
         FORJ (0, n) {
            int a = i, b = j;
            while (moves[a][b] != make_pair (a, b)) {
               tie (a, b) = moves[a][b];               
            }

            grid[a][b]++;
         }
      }

      return grid;
   }

   vector<int> find_answer (const vvi& c)
   {
      int x = 0, y = 0; // x = houses w/ > 1 person, y = max ppl

      FORI (0, n) {
         FORJ (0, n) {
            if (c[i][j] >= 1) x++;
            y = max (y, c[i][j]);
         }
      }

      return { x, y };
   }

   vector<int> find (int r, vector<int> t)
   {
      n = sqrt (t.size ());
      
      auto a = initialize_grid (t);
      auto b = initialize_moves (r, a);
      auto c = initialize_final_pos (b);     
      
      return find_answer (c);
   }
};
