// code_report Solution
// https://youtu.be/RzobVOY4Qb8

#include <cmath>

using namespace std;

class TheRoundCityDiv2
{
public:

   int find (int r) 
   {
      int c = -1;
      for (int i = -r; i <= r; ++i) {
         for (int j = -r; j <= r; ++j) {
            if (sqrt (i*i + j*j) <= r) c++;
         }
      }
      return c;
   }

};
