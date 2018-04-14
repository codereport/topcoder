// code_report Solution
//

#include <vector>
#include <algorithm>

using namespace std;

class MinimizeAbsoluteDifferenceDiv2 {
public:

   double calc_diff (double a, double b, double c) {
      return abs (a / b - c);
   }

   vector <int> findTriple (int x0, int x1, int x2) 
   {
      vector<int> v = { x0, x1, x2 }, o = { 0, 1, 2 }, ans;

      double min_ = numeric_limits<double>::max ();

      do {
         double diff = calc_diff (v[o[0]], v[o[1]], v[o[2]]);
         if (diff < min_) min_ = diff, ans = o;
      } while (next_permutation (o.begin (), o.end ()));

      return ans;
   }
};
