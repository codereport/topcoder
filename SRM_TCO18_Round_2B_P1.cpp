// code_report
// 

#include <vector>
#include <algorithm>

using namespace std;

vector <double> findBest (const vector<int>& a) 
{
   int n = a.size (), start = 0, end = 0;
   vector<double> ans (n);
   
   while (start < n) 
   {
      double sum = 0, avg = a[start], avg_j = 0;
      
      for (int i = start; i < n; ++i) 
      {
         sum += a[i];
         avg_j = sum / (i - start + 1);
         if (avg_j < avg) avg = avg_j, end = i;
      }

      fill (ans.begin () + start, ans.begin () + end + 1, avg);
      ++end, start = end;
   }

   return ans;
}
