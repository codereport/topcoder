// code_report
// https://youtu.be/y3vnhJ2rrd0

#include <vector>
#include <algorithm>

using namespace std;

// C++11

class BirthdayCandy {
public:
	int mostCandy(int K, vector<int> c) {
        auto l = [K](int e) { return e / (K+1) + e % (K+1); };
		    vector<int> v(c.size());
        transform(begin(c), end(c), begin(v), l);
		    return *max_element(begin(v), end(v));
    }
};

// C++20

class BirthdayCandy {
public:
   int mostCandy(int K, vector c) {
      auto l = [K](auto e) { return e / (K + 1) + e % (K + 1); };
      vector v(c.size());
      transform(c, v, l);
      return *max_element(v);
   }
};

// C++2x?

class BirthdayCandy {
public:
   int mostCandy(int K, vector c) {
      auto l = [K](auto e) { return e / (K + 1) + e % (K + 1); };
      auto v = transform(c, l);
      return *max_element(v);
   }
};
