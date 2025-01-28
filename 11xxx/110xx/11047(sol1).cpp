#include <algorithm>
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

    std::reverse(coins.begin(), coins.end());

    int res = 0, remaining_amount = k;
    for (const auto& val : coins) {
        if (!remaining_amount) break;
        res += remaining_amount / val;
        remaining_amount %= val;
    }

    std::cout << res << '\n';

    return 0;
}