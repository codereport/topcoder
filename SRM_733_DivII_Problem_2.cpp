// code_report Solution
// 

#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class BuildingSpanningTreesDiv2
{
public: 

   void quick_union (int x, int y, vector<int>& rt, vector<int>& sz)
   {
      while (x != rt[x]) x = rt[x];
      while (y != rt[y]) y = rt[y];
      if (x == y) return;
      rt[x] = rt[y];
      sz[y] += sz[x];
   }

   int getNumberOfSpanningTrees (int n, vector <int> x, vector <int> y)
   {
      int m = n - 3;

      // make x and y 0-indexed
      auto minus_one = [](int i) { return i - 1; };
      transform (x.begin (), x.end (), x.begin (), minus_one);
      transform (y.begin (), y.end (), y.begin (), minus_one);

      vector<int> rt (n);    // after quick union, will store "root" of connected component
      vector<int> sz (n, 1); // after quick union, will store "size" of each root
      iota (rt.begin (), rt.end (), 0);

      for (int i = 0; i < m; i++) quick_union (x[i], y[i], rt, sz);

      vector<long long> comp; // will store size of each connected component 
      for (int i = 0; i < n; i++) if (rt[i] == i) comp.push_back (sz[i]);

      if (comp.size () != 3) return 0;

      long long A = comp[0] * comp[1]; // edge 1
      long long B = comp[1] * comp[2]; // edge 2
      long long C = comp[0] * comp[2]; // edge 3

      const int MOD = 987654323;
      
      return (A*B + B*C + A*C) % MOD;;
   }
};
