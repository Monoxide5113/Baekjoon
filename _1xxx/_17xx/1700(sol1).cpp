#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> device_order(k);
    for (auto& val : device_order)
        std::cin >> val;

    std::vector<int> multitap(n, 0);

    auto find_replacement_idx = [&](int cur_idx) {
        int ret, furthest_nxt_used_idx = 0;
        for (int i = 0; i < n; ++i) {
            const auto search_start = device_order.begin() + cur_idx + 1;
            const auto nxt_used_it = std::find(search_start, device_order.end(), multitap[i]);
            if (nxt_used_it == device_order.end()) return i;

            const int nxt_used_idx = std::distance(device_order.begin(), nxt_used_it);
            if (nxt_used_idx <= furthest_nxt_used_idx) continue;
            furthest_nxt_used_idx = nxt_used_idx;
            ret = i;
        }
        return ret;
    };

    int res = 0;
    for (int i = 0; i < k; ++i) {
        const auto cur_it = std::find(multitap.begin(), multitap.end(), device_order[i]);
        if (cur_it != multitap.end()) continue;

        const auto empty_it = std::find(multitap.begin(), multitap.end(), 0);
        if (empty_it != multitap.end()) {
            *empty_it = device_order[i];
            continue;
        }

        const int replacement_idx = find_replacement_idx(i);
        multitap[replacement_idx] = device_order[i];
        ++res;
    }

    std::cout << res << '\n';
}