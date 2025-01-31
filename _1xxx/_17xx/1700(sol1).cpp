#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> schedule(k);
    for (auto& val : schedule)
        std::cin >> val;

    std::vector<int> extension_cord(n, 0);

    auto find_replace_idx = [&](int start_idx) {
        int replace_idx, furthest_used_idx = 0;
        for (int i = 0; i < n; ++i) {
            const auto search_start = schedule.begin() + start_idx + 1;
            const auto it = std::find(search_start, schedule.end(), extension_cord[i]);
            if (it == schedule.end()) return i;

            const int nxt_used_idx = std::distance(schedule.begin(), it);
            if (nxt_used_idx <= furthest_used_idx) continue;
            furthest_used_idx = nxt_used_idx;
            replace_idx = i;
        }
        return replace_idx;
    };

    int res = 0;
    for (int i = 0; i < k; ++i) {
        const auto cur_it = std::find(extension_cord.begin(), extension_cord.end(), schedule[i]);
        if (cur_it != extension_cord.end()) continue;

        const auto available_it = std::find(extension_cord.begin(), extension_cord.end(), 0);
        if (available_it != extension_cord.end()) {
            *available_it = schedule[i];
            continue;
        }

        const int replace_idx = find_replace_idx(i);
        extension_cord[replace_idx] = schedule[i];
        ++res;
    }

    std::cout << res << '\n';
}