// code_report Solution
// 

#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

class chess_board {
   vvi g;
   vi dx = { 0,  0, 1, -1, 1,  1, -1, -1 };
   vi dy = { 1, -1, 0,  0, 1, -1,  1, -1 };
   const int DIR = 8, DIM = 50;

   bool is_valid(int x, int y) {
      return x >= 0 && x < DIM && y >= 0 && y < DIM;
   }

public:

   chess_board() : g(DIM, vi(DIM, 0)) {}
    
   void place_queen(int x, int y) {
      for (int i = 0; i < DIR; ++i) {
         int r = x, c = y;
         while (is_valid(r, c)) 
            g[r][c] = 1, r += dx[i], c += dy[i];
      }
   }

   pair<int,int> find_and_place_next_queen() {
      for (int i = 0; i < DIM; ++i) {
         for (int j = 0; j < DIM; ++j) {
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
