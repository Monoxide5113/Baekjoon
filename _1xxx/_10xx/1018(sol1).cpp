#include <algorithm>
#include <iostream>
#include <vector>

constexpr int CUT_SIZE = 8;
constexpr char WHITE = 'W', BLACK = 'B';

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<char>> board(n, std::vector<char>(m));
    for (auto& line : board)
        for (auto& val : line)
            std::cin >> val;

    auto get_mismatched = [&](int start_y, int start_x) {
        int white_cnt = 0, black_cnt = 0;
        for (int y = 0; y < CUT_SIZE; ++y) {
            for (int x = 0; x < CUT_SIZE; ++x) {
                const char target_color = ((y + x) % 2) ? WHITE : BLACK;
                (board[start_y + y][start_x + x] == target_color) ? ++white_cnt : ++black_cnt;
            }
        }
        return std::min(white_cnt, black_cnt);
    };

    int res = CUT_SIZE * CUT_SIZE;
    const int max_y = n - CUT_SIZE + 1, max_x = m - CUT_SIZE + 1;
    for (int y = 0; y < max_y; ++y)
        for (int x = 0; x < max_x; ++x)
            res = std::min(res, get_mismatched(y, x));

    std::cout << res << '\n';

    return 0;
}