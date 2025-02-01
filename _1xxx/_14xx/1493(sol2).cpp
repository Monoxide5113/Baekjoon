#include <algorithm>
#include <array>
#include <iostream>

constexpr int MAX_CUBE_SIZE = 20;
constexpr int NONE = -1;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int l, w, h, n;
    std::cin >> l >> w >> h >> n;

    std::array<int, MAX_CUBE_SIZE> cube_cnts;
    cube_cnts.fill(0);
    for (int i = 0; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        cube_cnts[a] = b;
    }

    int used_cube_cnt = 0;
    long long filled_volume = 0;
    for (int i = MAX_CUBE_SIZE - 1; i >= 0; --i) {
        filled_volume <<= 3;
        const int cube_size = 1 << i;
        const long long max_volume = 1LL * (l / cube_size) * (w / cube_size) * (h / cube_size);
        const int valid_volume = max_volume - filled_volume;
        const int cnt = std::min(valid_volume, cube_cnts[i]);
        filled_volume += cnt;
        used_cube_cnt += cnt;
    }

    const bool can_fill = filled_volume == 1LL * l * w * h;
    const int res = can_fill ? used_cube_cnt : -1;
    std::cout << res << '\n';
}