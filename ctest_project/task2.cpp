#include "task2.h"

#include <algorithm>
#include <cmath>

bool can_reach(int sx, int sy, int fx, int fy, unsigned int t) {
    const int dx = std::abs(sx - fx);
    const int dy = std::abs(sy - fy);
    const unsigned int min_steps = static_cast<unsigned int>(std::max(dx, dy));
    return t >= min_steps;
}
