#include <algorithm>
#include <array>
#include <iostream>
#include <utility>

constexpr int TOTAL_CNT = 11;
constexpr int PENALTY_FACTOR = 20;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::array<std::pair<int, int>, TOTAL_CNT> problems;
    for (auto& [d, v] : problems)
        std::cin >> d >> v;

    std::sort(problems.begin(), problems.end());

    int res = 0, accumulated_delay = 0;
    for (const auto& [d, v] : problems) {
        accumulated_delay += d;
        res += accumulated_delay + PENALTY_FACTOR * v;
    }

    std::cout << res << '\n';

    return 0;
}