#include "task4.h"

#include <algorithm>
#include <limits>

namespace {
int to_minutes(const std::string& value) {
    const int hour = (value[0] - '0') * 10 + (value[1] - '0');
    const int minute = (value[3] - '0') * 10 + (value[4] - '0');
    return hour * 60 + minute;
}
}  // namespace

int min_time_difference(const std::vector<std::string>& time_points) {
    std::vector<int> minutes;
    minutes.reserve(time_points.size());
    for (const std::string& t : time_points) {
        minutes.push_back(to_minutes(t));
    }

    std::sort(minutes.begin(), minutes.end());
    int answer = std::numeric_limits<int>::max();
    for (std::size_t i = 1; i < minutes.size(); ++i) {
        answer = std::min(answer, minutes[i] - minutes[i - 1]);
    }
    answer = std::min(answer, 1440 - minutes.back() + minutes.front());
    return answer;
}
