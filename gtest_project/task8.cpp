#include "task8.h"

#include <algorithm>
#include <set>
#include <utility>

namespace {
int cross(const std::vector<int>& o, const std::vector<int>& a, const std::vector<int>& b) {
    return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0]);
}
}  // namespace

std::vector<std::vector<int>> outer_trees(const std::vector<std::vector<int>>& trees) {
    if (trees.size() <= 1) {
        return trees;
    }

    std::vector<std::vector<int>> points = trees;
    std::sort(points.begin(), points.end(), [](const std::vector<int>& lhs, const std::vector<int>& rhs) {
        if (lhs[0] == rhs[0]) {
            return lhs[1] < rhs[1];
        }
        return lhs[0] < rhs[0];
    });

    std::vector<std::vector<int>> hull;
    for (const auto& p : points) {
        while (hull.size() >= 2 && cross(hull[hull.size() - 2], hull.back(), p) < 0) {
            hull.pop_back();
        }
        hull.push_back(p);
    }

    const std::size_t lower_size = hull.size();
    for (int i = static_cast<int>(points.size()) - 2; i >= 0; --i) {
        while (hull.size() > lower_size && cross(hull[hull.size() - 2], hull.back(), points[i]) < 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    if (!hull.empty()) {
        hull.pop_back();
    }

    std::set<std::pair<int, int>> unique_points;
    std::vector<std::vector<int>> answer;
    for (const auto& p : hull) {
        std::pair<int, int> key = {p[0], p[1]};
        if (unique_points.insert(key).second) {
            answer.push_back(p);
        }
    }
    return answer;
}
