#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> sensors(n);
    for (auto& val : sensors)
        std::cin >> val;

    std::sort(sensors.begin(), sensors.end());

    std::vector<int> diffs(n - 1);
    for (int i = 0; i < n - 1; ++i)
        diffs[i] = sensors[i + 1] - sensors[i];

    std::sort(diffs.begin(), diffs.end());

    const int required_gaps = std::max(0, n - k);
    const int res = std::accumulate(diffs.begin(), diffs.begin() + required_gaps, 0);
    std::cout << res << '\n';
}