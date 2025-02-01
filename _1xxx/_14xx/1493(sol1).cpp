#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>

constexpr int MAX_CUBE_SIZE = 20;
constexpr int NONE = -1;
constexpr int MIN_CUBE_STATE = 1 << 0, MAX_CUBE_STATE = 1 << 3;
constexpr int FLAG_Z = 1 << 0, FLAG_Y = 1 << 1, FLAG_X = 1 << 2;

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

    auto find_largest_available_cube_idx = [&](int min_dim) {
        for (int i = MAX_CUBE_SIZE - 1; i >= 0; --i) {
            const int cube_size = 1 << i;
            if (cube_size > min_dim) continue;
            if (cube_cnts[i] == 0) continue;
            return i;
        }
        return NONE;
    };

    auto cal_partition_dim = [](int state, int flag, int dim, int cube_size) {
        return (state & flag) ? dim - cube_size : cube_size;
    };

    auto can_fill_remaining_space = [&](const auto& self, int z, int y, int x) {
        const int min_dim = std::min({z, y, x});
        if (min_dim == 0) return true;

        const int cube_idx = find_largest_available_cube_idx(min_dim);
        if (cube_idx == NONE) return false;

        --cube_cnts[cube_idx];
        const int cube_size = 1 << cube_idx;
        for (int state = MIN_CUBE_STATE; state < MAX_CUBE_STATE; ++state) {
            const int nz = cal_partition_dim(state, FLAG_Z, z, cube_size);
            const int ny = cal_partition_dim(state, FLAG_Y, y, cube_size);
            const int nx = cal_partition_dim(state, FLAG_X, x, cube_size);
            const bool can_fill = self(self, nz, ny, nx);
            if (!can_fill) return false;
        }
        return true;
    };

    const int total_cnt = std::accumulate(cube_cnts.begin(), cube_cnts.end(), 0);
    const bool can_fill = can_fill_remaining_space(can_fill_remaining_space, h, w, l);
    const int remaining_cnt = std::accumulate(cube_cnts.begin(), cube_cnts.end(), 0);
    const int res = can_fill ? total_cnt - remaining_cnt : NONE;
    std::cout << res << '\n';
}