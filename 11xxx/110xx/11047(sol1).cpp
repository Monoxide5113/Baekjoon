#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> coins(n);
    for (auto& val : coins)
        std::cin >> val;

    int res = 0, remaining_amount = k;
    for (auto it = coins.crbegin(); it != coins.crend(); ++it) {
        const auto coin = *it;
        res += remaining_amount / coin;
        remaining_amount %= coin;
        if (remaining_amount == 0) break;
    }

    std::cout << res << '\n';

    return 0;
}