// code_report Solution
// https://youtu.be/5zQQSeatnOE

#include <string>
using namespace std;

// Solution 1

string canItBeDone(int l, int p) {
   for (int i = 1; i <= p; ++i) l -= i;
   return l >= 0 ? "possible" : "impossible";
}

// Solution 2

string canItBeDone(int l, int p) {
   return (p*(p + 1))/2 <= l ? "possible" : "impossible";
}
