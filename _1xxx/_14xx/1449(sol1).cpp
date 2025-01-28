#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, l;
    std::cin >> n >> l;

    std::vector<int> pos(n);
    for (auto& val : pos)
        std::cin >> val;

    std::sort(pos.begin(), pos.end());

    int res = 1, last_covered_pos = pos[0];
    for (auto it = pos.cbegin() + 1; it != pos.cend(); ++it) {
        const auto& cur_pos = *it;
        if (cur_pos - last_covered_pos < l) continue;
        last_covered_pos = cur_pos;
        ++res;
    }

    std::cout << res << '\n';

    return 0;
}