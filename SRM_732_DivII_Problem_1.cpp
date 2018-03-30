// code_report Solution
// https://youtu.be/nggxQeCUbtw

#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string IsValid (int n, vector <int> value, string suit) {

	unordered_map<char, int> m;
	unordered_set<int> nums;

	for (int i = 0; i < n; i++) {
		m[suit[i]]++;
		nums.insert (value[i]);
	}

	for (const auto& s : m) {
		if (nums.size () != s.second) return "Not perfect";
	}

	return "Perfect";
}

string IsValid2 (int n, vector <int> value, string suit) {

	unordered_map<char, int> m;

	for (int i = 0; i < n; i++) m[suit[i]]++;

	sort (value.begin (), value.end ());
	auto it = unique (value.begin (), value.end ());
	auto unique_count = distance (value.begin (), it);
	auto size_equal_unique_count = [unique_count](const auto& p) { return unique_count == p.second; };

	return (all_of (m.begin (), m.end (), size_equal_unique_count) ? "Perfect" : "Not perfect");
}
