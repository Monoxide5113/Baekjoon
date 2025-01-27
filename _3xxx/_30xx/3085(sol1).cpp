#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::vector<char>> board(n, std::vector<char>(n));
    for (auto& line : board)
        for (auto& val : line)
            std::cin >> val;

    auto get_max_y = [&](int y) {
        int ret = 1, cnt = 1;
        for (int x = 0; x < n - 1; ++x) {
            cnt = (board[y][x] == board[y][x + 1]) ? cnt + 1 : 1;
            ret = std::max(ret, cnt);
        }
        return ret;
    };

    auto get_max_x = [&](int x) {
        int ret = 1, cnt = 1;
        for (int y = 0; y < n - 1; ++y) {
            cnt = (board[y][x] == board[y + 1][x]) ? cnt + 1 : 1;
            ret = std::max(ret, cnt);
        }
        return ret;
    };

    int res = 1;
    for (int i = 0; i < n; ++i)
        res = std::max({res, get_max_y(i), get_max_x(i)});
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n - 1; ++x) {
            std::swap(board[y][x], board[y][x + 1]);
            res = std::max({res, get_max_y(y), get_max_x(x), get_max_x(x + 1)});
            std::swap(board[y][x], board[y][x + 1]);
        }
    }
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n - 1; ++y) {
            std::swap(board[y][x], board[y + 1][x]);
            res = std::max({res, get_max_x(x), get_max_y(y), get_max_y(y + 1)});
            std::swap(board[y][x], board[y + 1][x]);
        }
    }

    std::cout << res << '\n';

    return 0;
}