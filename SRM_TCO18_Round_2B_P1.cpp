// code_report
// 

#include <vector>
#include <algorithm>

using namespace std;

vector<double> findBest (const vector<int>& a)
{
   vector<double> b (a.begin (), a.end ());
   auto start = b.begin ();
   auto end   = start;

   while (start != b.end ()) {
      auto sum   = 0.0;
      auto avg   = *start;
      auto avg_i = 0.0;

      for (auto i = start; i != b.end (); ++i) {
         sum  += *i;
         avg_i = sum / (distance (start, i) + 1);
         if (avg_i < avg) avg = avg_i, end = i + 1;
      }

      fill (start, end, avg);
      start = end;
   }

   return b;
}

