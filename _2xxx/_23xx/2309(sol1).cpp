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

    std::pair<int, int> fake_idxs;
    const int total_sum = std::accumulate(dwarfs.begin(), dwarfs.end(), 0);
    const int diff = total_sum - TARGET_SUM;
    bool is_found = false;
    for (int i = 0; i < TOTAL_CNT - 1 && !is_found; ++i) {
        for (int j = i + 1; j < TOTAL_CNT; ++j) {
            const int cur_diff = dwarfs[i] + dwarfs[j];
            if (cur_diff != diff) continue;
            fake_idxs = { i, j };
            is_found = true;
            break;
        }
    }

    const auto [fake_idx1, fake_idx2] = fake_idxs;
    for (const auto val : dwarfs) {
        if (val == dwarfs[fake_idx1] || val == dwarfs[fake_idx2]) continue;
        std::cout << val << '\n';
    }

    return 0;
}