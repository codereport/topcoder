// code_report Solution
// https://youtu.be/_eD3HE4piYs

#include <vector>
#include <string>

using namespace std;

class HamiltonianPathsInGraph
{
public:

   vector<int> findPath (vector<string> X)
   {
      vector<int> path = { 0 };

      for (int i = 1; i < X.size (); ++i) {
         for (int j = 0; j <= path.size (); ++j)
         {
            if (j < path.size () && X[i][path[j]]     != '+') continue;
            if (j > 0            && X[path[j - 1]][i] != '+') continue;

            path.insert (path.begin () + j, i);
            break;
         }
      }

      return path;
   }
};
