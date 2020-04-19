#include <numeric>
#include <algorithm>

double solve(std::vector<int> p) {
    std::sort(p.begin(), p.end());
    auto it = std::unique(p.begin(), p.end());
    double n = std::distance(p.begin(), it);
    return std::accumulate(p.begin(), it, 0) / n;
}
