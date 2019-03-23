// code_report Solution
// Video Link: https://youtu.be/mdn7bsuK0Wo
// Problem Link: https://arena.topcoder.com/#/u/practiceCode/17449/85533/15355/2/332231

#include <string>
#include <numeric>

using namespace std;

class KerimJavati {
   public:
   int howLong(string text) {
      return accumulate(text.begin(), text.end(), 0, 
         [](int a, char b) { return a + 2 * (b - 'a') + 1; });
   }
};
