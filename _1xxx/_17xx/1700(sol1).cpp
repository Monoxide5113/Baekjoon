#include <algorithm>
#include <iostream>
#include <vector>

constexpr int EMPTY_SLOT = 0;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> schedule(k);
    for (auto& val : schedule)
        std::cin >> val;
    
    std::vector<int> multitap(n, EMPTY_SLOT);

    auto find_replace_idx = [&](int start_idx) {
        int replace_idx, furthest_idx = 0;
        for (int i = 0; i < n; ++i) {
            const auto start_it = schedule.begin() + start_idx + 1, end_it = schedule.end();
            const auto it = std::find(start_it, end_it, multitap[i]);
            if (it == schedule.end()) return i;

            const int nxt_used_idx = std::distance(schedule.begin(), it);
            if (nxt_used_idx <= furthest_idx) continue;
            furthest_idx = nxt_used_idx;
            replace_idx = i;
        }
        return replace_idx;
    };

    int res = 0;
    for (int i = 0; i < k; ++i) {
        const auto cur_it = std::find(multitap.begin(), multitap.end(), schedule[i]);
        if (cur_it != multitap.end()) continue;

        const auto empty_it = std::find(multitap.begin(), multitap.end(), EMPTY_SLOT);
        if (empty_it != multitap.end()) {
            *empty_it = schedule[i];
            continue;
        }

        const int replace_idx = find_replace_idx(i);
        multitap[replace_idx] = schedule[i];
        ++res;
    }

    std::cout << res << '\n';

    return 0;
}