// code_report Solution
// 

#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class BuildingSpanningTreesDiv2
{
public:

   const int MOD = 987654323;

   void quick_union (int x, int y, vector<int>& rt, vector<int>& sz)
   {
      while (x != rt[x]) x = rt[x];
      while (y != rt[y]) y = rt[y];
      if (x == y) return;
      rt[x] = rt[y];
      sz[y] += sz[x];
   }

   int getNumberOfSpanningTrees (int n, vector<int> x, vector<int> y)
   {
      int m = n - 3;

      for (auto& e : x) e--; // make x 0-indexed
      for (auto& e : y) e--; // make y 0-indexed

      vector<int> rt (n);    // after quick union, will store "root" of connected component
      vector<int> sz (n, 1); // after quick union, will store "size" of each connected component
      iota (rt.begin (), rt.end (), 0);

      for (int i = 0; i < m; i++) quick_union (x[i], y[i], rt, sz);

      vector<long long> comp; // will store size of each connected component 
      for (int i = 0; i < n; i++) if (rt[i] == i) comp.push_back (sz[i]);

      if (comp.size () != 3) return 0;

      long long A = comp[0] * comp[1]; // edge 1
      long long B = comp[1] * comp[2]; // edge 2
      long long C = comp[0] * comp[2]; // edge 3

      return (A*B + B*C + A*C) % MOD;
   }
};
