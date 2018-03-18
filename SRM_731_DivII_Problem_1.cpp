// code_report Solution
// https://youtu.be/O-0_JErkut4?t=10m12s

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string getmin (string t) 
{
	int n = t.size ();
	string s (n, 'z');

	const vector<int> primes { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47 };

	for (int i = 0; i < n; ++i) {
		for (int prime : primes) {
			if (prime >= n) break;
			string temp;
			for (int j = 0; j < n; ++j) temp += t[(i + prime * j) % n];
			s = min (s, temp);
		}
	}

	return s;
}
