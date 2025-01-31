#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <utility>

constexpr int TOTAL_CNT = 9;
constexpr int TARGET_SUM = 100;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::array<int, TOTAL_CNT> dwarfs;
    for (auto& dwarf : dwarfs)
        std::cin >> dwarf;

    std::sort(dwarfs.begin(), dwarfs.end());

    auto find_fakes = [&]() {
        const int total_sum = std::accumulate(dwarfs.begin(), dwarfs.end(), 0);
        const int diff = total_sum - TARGET_SUM;
        for (int i = 0; i < TOTAL_CNT; ++i) {
            for (int j = i + 1; j < TOTAL_CNT; ++j) {
                if (dwarfs[i] + dwarfs[j] != diff) continue;
                return std::pair<int, int>(dwarfs[i], dwarfs[j]);
            }
        }
    };

    const auto [fake1, fake2] = find_fakes();
    for (const auto val : dwarfs) {
        if (val == fake1 || val == fake2) continue;
        std::cout << val << '\n';
    }

    return 0;
}