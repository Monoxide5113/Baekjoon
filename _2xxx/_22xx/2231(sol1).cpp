#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>

constexpr int MAX_VAL_SINGLE_DIGIT = 9;
constexpr char ZERO_CHAR = '0';

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    auto sum_digits = [](int num) {
        const auto str_num = std::to_string(num);
        return std::accumulate(str_num.cbegin(), str_num.cend(), 0, [](int acc, char x) {
            return acc + (x - ZERO_CHAR); 
        });
    };

    int res = 0;
    const int n_digit_cnt = std::to_string(n).size();
    const int min_num = std::max(1, n - MAX_VAL_SINGLE_DIGIT * n_digit_cnt);
    for (int num = min_num; num < n; ++num) {
        const int cur_sum = num + sum_digits(num);
        if (cur_sum != n) continue;
        res = num;
        break;
    }

    std::cout << res << '\n';

    return 0;
}