// code_report Solution
// https://youtu.be/3EUxow6Ysw8

#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class CubeStackingGame {
public:

	using vi  = vector<int>;
	using usi = unordered_set<int>;

	int res = 0, N;
	vi  e, f, g, h;	// colors 
	usi a, b, c, d; // stacks

	void modify_stacks_then_dfs (int i, int p, int q, int r, int s)
	{
		if (!a.count (p) && !b.count (q) && !c.count (r) && !d.count (s))
		{
			auto it1 = a.insert (p).first;
			auto it2 = b.insert (q).first;
			auto it3 = c.insert (r).first;
			auto it4 = d.insert (s).first;
			dfs (i + 1);
			a.erase (it1);
			b.erase (it2);
			c.erase (it3);
			d.erase (it4);
		}
	}

	void dfs (int i)
	{
		res = max (res, i);
		if (i == N) return;

		modify_stacks_then_dfs (i, e[i], f[i], g[i], h[i]);
		modify_stacks_then_dfs (i, f[i], g[i], h[i], e[i]);
		modify_stacks_then_dfs (i, g[i], h[i], e[i], f[i]);
		modify_stacks_then_dfs (i, h[i], e[i], f[i], g[i]);
		modify_stacks_then_dfs (i, h[i], g[i], f[i], e[i]);
		modify_stacks_then_dfs (i, g[i], f[i], e[i], h[i]);
		modify_stacks_then_dfs (i, f[i], e[i], h[i], g[i]);
		modify_stacks_then_dfs (i, e[i], h[i], g[i], f[i]);
	}

	int MaximumValue (int n, vi c1, vi c2, vi c3, vi c4)
	{
		e = c1, f = c2, g = c3, h = c4, N = n;

		dfs (0);

		return res;
	}
};

// un-rolled out, more STL solution

class CubeStackingGame {
public:

	using vi  = vector<int>;
	using vvi = vector<vi>;

	int res = 0, N;
	vi e, f, g, h;

	void modify (int i, const vector<int>& c, vvi& s) {
		bool perform_dfs = true;
		for (int j = 0; j < 4; j++) if (s[j][c[j]]) perform_dfs = false;

		if (perform_dfs) {
			for (int j = 0; j < 4; ++j) s[j][c[j]] = 1;
			dfs (i + 1, s);
			for (int j = 0; j < 4; j++) s[j][c[j]] = 0;
		}
	}

	void dfs (int i, vvi& s) {
		res = max (res, i);
		if (i == N) return;

		vector<int> c = { e[i], f[i], g[i], h[i] }; // colors

		for (int j = 0; j < 8; j++) {
			if (j == 4) reverse (c.begin (), c.end ());
			modify (i, c, s);
			rotate (c.begin (), c.begin () + 1, c.end ());
		}
	}

	int MaximumValue (int n, vi c1, vi c2, vi c3, vi c4) {
		e = c1, f = c2, g = c3, h = c4, N = n;
		vvi s (4, vi (n + 1, 0));

		dfs (0, s);

		return res;
	}
};
