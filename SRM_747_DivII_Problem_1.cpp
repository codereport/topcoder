// code_report Solution
// Video Link: https://youtu.be/g0MsAyI_zGI
// Problem Link: https://arena.topcoder.com/#/u/practiceCode/17404/78412/15285/2/332030

#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class Sherlock {
public:
    string isItHim(string f, string l) {
        set<char> b = {'B','E','N','D','I','C','T'};
        set<char> c = {'C','U','M','B','E','R','A','T','H'};
        auto isHim = f.size() >= 7 && 
                     l.size() >= 7 && 
                     f[0] == 'B'   &&
                     l[0] == 'C'   && 
                     count_if(f.begin(), f.end(), [&b](char e) { return b.count(e); }) >= 3 && 
                     count_if(l.begin(), l.end(), [&c](char e) { return c.count(e); }) >= 5;
        return isHim ? "It is him" : "It is someone else";
    }
};
