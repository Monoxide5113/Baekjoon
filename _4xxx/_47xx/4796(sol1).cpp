#include <algorithm>
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tc = 1;
    while (true) {
        int l, p, v;
        std::cin >> l >> p >> v;
        if (l == 0 && p == 0 && v == 0) break;

        const int cycles = v / p, remaining_days = v % p;
        const int res = cycles * l + std::min(remaining_days, l);
        std::cout << "Case " << tc << ": " << res << '\n';
        ++tc;
    }

    return 0;
}