// code_report Solution
// 

#include <vector>
#include <string>

using namespace std;

using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int r, c;

void dfs (vvi& v, const vs& a, int x, int y, int m) 
{
   auto is_valid = [](int x, int y) {
      return x >= 0 && x < r &&
             y >= 0 && y < c;
   };

   if (v[x][y] == -1 || v[x][y] > m) 
   {
      v[x][y] = m;
      for (int i = 0; i < 4; ++i) {
         int nx = x + dx[i];
         int ny = y + dy[i];
         if (is_valid (nx, ny)) {
            if (a[nx][ny] == '.') {
               dfs (v, a, nx, ny, m + 1);
            } else {
               do {
                  if (a[nx][ny] == '.') {
                     dfs (v, a, nx, ny, m + 2);
                     break;
                  }
                  nx += dx[i], ny += dy[i];
               } while (is_valid (nx, ny));
            }
         }
      }
   }
}

int pathLength (vector<string> a, int r1, int c1, int r2, int c2) 
{
   r = a.size ();
   c = a[0].size ();
   vvi v (r, vi (c, -1));

   dfs (v, a, r1, c1, 0);

   return v[r2][c2];
}
