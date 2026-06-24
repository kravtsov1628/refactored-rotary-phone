#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>

#include "../task3.h"
#include "../task4.h"
#include "../task5.h"
#include "../task6.h"
#include "../task7.h"
#include "../task8.h"

namespace {
std::vector<std::string> normalize_points(const std::vector<std::vector<int>>& points) {
    std::vector<std::string> normalized;
    normalized.reserve(points.size());
    for (const auto& p : points) {
        normalized.push_back(std::to_string(p[0]) + "," + std::to_string(p[1]));
    }
    std::sort(normalized.begin(), normalized.end());
    return normalized;
}

}
TEST(Task3EquationSolver, BasicEquation) {
    EXPECT_EQ(solve_equation("x+2x+1-2=6+x-1"), "x=3");
}

TEST(Task3EquationSolver, NoSolution) {
    EXPECT_EQ(solve_equation("x=x+1"), "NO");
}

TEST(Task3EquationSolver, InfiniteSolutions) {
    EXPECT_EQ(solve_equation("2x-x=x"), "Infinite");
}

TEST(Task4MinTimeDifference, WrapAroundMidnight) {
    EXPECT_EQ(min_time_difference({"23:59", "00:00"}), 1);
}

TEST(Task4MinTimeDifference, SimpleCase) {
    EXPECT_EQ(min_time_difference({"01:00", "03:00", "02:30"}), 30);
}

TEST(Task4MinTimeDifference, EqualTimes) {
    EXPECT_EQ(min_time_difference({"10:10", "10:10"}), 0);
}

TEST(Task5GridReachability, TargetPointOne) {
    EXPECT_TRUE(can_reach_from_one(1, 1));
}

TEST(Task5GridReachability, PositiveCoordinates) {
    EXPECT_TRUE(can_reach_from_one(7, 11));
}

TEST(Task5GridReachability, ZeroAxisPowerOfTwoOnly) {
    EXPECT_TRUE(can_reach_from_one(0, 8));
    EXPECT_FALSE(can_reach_from_one(0, 6));
    EXPECT_FALSE(can_reach_from_one(0, 0));
}

TEST(Task6ExpressionEval, BasicWithSpaces) {
    EXPECT_EQ(evaluate_expression("1 + 1"), 2);
}

TEST(Task6ExpressionEval, ParenthesesAndUnaryMinus) {
    EXPECT_EQ(evaluate_expression("-(2 + 3) + 10"), 5);
}

TEST(Task6ExpressionEval, NestedParentheses) {
    EXPECT_EQ(evaluate_expression("(1+(4+5+2)-3)+(6+8)"), 23);
}

TEST(Task7NoConsecutiveOnes, SmallN) {
    EXPECT_EQ(count_without_consecutive_ones(5), 5ULL);
}

TEST(Task7NoConsecutiveOnes, ZeroN) {
    EXPECT_EQ(count_without_consecutive_ones(0), 1ULL);
}

TEST(Task7NoConsecutiveOnes, MediumN) {
    EXPECT_EQ(count_without_consecutive_ones(10), 8ULL);
}

TEST(Task8FencePerimeter, ExampleConvexHullWithInnerPoint) {
    const std::vector<std::vector<int>> trees = {{1, 1}, {2, 2}, {2, 0}, {2, 4}, {3, 3}, {4, 2}};
    const auto result = normalize_points(outer_trees(trees));
    const std::vector<std::string> expected = {"1,1", "2,0", "2,4", "3,3", "4,2"};
    EXPECT_EQ(result, expected);
}

TEST(Task8FencePerimeter, AllPointsOnLine) {
    const std::vector<std::vector<int>> trees = {{1, 1}, {2, 2}, {3, 3}};
    const auto result = normalize_points(outer_trees(trees));
    const std::vector<std::string> expected = {"1,1", "2,2", "3,3"};
    EXPECT_EQ(result, expected);
}

TEST(Task8FencePerimeter, RectangleCorners) {
    const std::vector<std::vector<int>> trees = {{0, 0}, {0, 2}, {2, 0}, {2, 2}, {1, 1}};
    const auto result = normalize_points(outer_trees(trees));
    const std::vector<std::string> expected = {"0,0", "0,2", "2,0", "2,2"};
    EXPECT_EQ(result, expected);
}
