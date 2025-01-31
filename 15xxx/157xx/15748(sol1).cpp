#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using Rest_stop = std::pair<int, int>;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int l, n, rf, rb;
    std::cin >> l >> n >> rf >> rb;

    std::vector<Rest_stop> rest_stops(n);
    for (auto& [c, x] : rest_stops)
        std::cin >> c >> x;

    std::sort(rest_stops.begin(), rest_stops.end(), std::greater<>());

    long long res = 0;
    const int time_diff = rf - rb;
    int last_stop = 0;
    for (const auto [c, x] : rest_stops) {
        if (x <= last_stop) continue;
        const int dist = x - last_stop;
        res += 1LL * dist * time_diff * c;
        last_stop = x;
    }

    std::cout << res << '\n';
}