#include <bitset>
#include <iostream>
#include <vector>

constexpr int MAX = 1'001;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> tri_nums;
    int cur_tri = 0;
    for (int i = 1; cur_tri + i < MAX; ++i) {
        cur_tri += i;
        tri_nums.push_back(cur_tri);
    }

    std::bitset<MAX + 1> tri_sums;
    const int tri_cnt = tri_nums.size();
    for (int i = 0; i < tri_cnt; ++i) {
        for (int j = i; j < tri_cnt; ++j) {
            for (int k = j; k < tri_cnt; ++k) {
                const int cur_tri_sum = tri_nums[i] + tri_nums[j] + tri_nums[k];
                if (cur_tri_sum >= MAX) continue;
                tri_sums.set(cur_tri_sum);
            }
        }
    }

    int t;
    std::cin >> t;

    for (int tc = 0; tc < t; ++tc) {
        int n;
        std::cin >> n;
        std::cout << tri_sums[n] << '\n';
    }

    return 0;
}