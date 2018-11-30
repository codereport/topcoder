// code_report Solution
// 

#include <vector>

#define FORI(s,n) for(int i = s; i < n; i++)
#define FORJ(s,n) for(int j = s; j < n; j++)

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

class chess_board {
   vvi g;
   vi dx = { 0,  0, 1, -1, 1, 1, -1, -1 };
   vi dy = { 1, -1, 0,  0, 1, -1, 1, -1 };

   bool is_valid(int x, int y) {
      return x >= 0 && x < 50 && y >= 0 && y < 50;
   }

public:

   chess_board() : g(50, vi(50, 0)) {}
    
   void place_queen(int x, int y) {
      FORI(0, 8) {
         int r = x, c = y;
         while (is_valid(r, c)) 
            g[r][c] = 1, r += dx[i], c += dy[i];
      }
   }

   pair<int,int> find_and_place_next_queen() {
      FORI(0, 50) {
         FORJ(0, 50) {
            if (g[i][j]) continue;
            place_queen(i, j);
            return make_pair(i, j);
         }
      }
   }
};

class SixteenQueens {
public:
   vi addQueens(vi row, vi col, int add) {
      chess_board cb;
      for (int i = 0; i < row.size(); ++i) 
         cb.place_queen(row[i], col[i]);
      vi ans;
      while (add--) {
         pair<int, int> p = cb.find_and_place_next_queen();
         ans.push_back(p.first);
         ans.push_back(p.second);
      }
      return ans;
   }
};
