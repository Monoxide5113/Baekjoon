#include <algorithm>
#include <bitset>
#include <iostream>
#include <utility>
#include <vector>

using Task = std::pair<int, int>;

constexpr int MAX_DAY = 1'001;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<Task> tasks(n);
    for (auto& [d, w] : tasks)
        std::cin >> d >> w;

    std::sort(tasks.begin(), tasks.end(), [](auto a, auto b) {
        return a.second != b.second ? a.second > b.second : a.first > b.first;
    });

    int res = 0;
    std::bitset<MAX_DAY> schedule;
    for (const auto [d, w] : tasks) {
        for (int i = d; i >= 1; --i) {
            if (schedule[i]) continue;
            schedule.set(i);
            res += w;
            break;
        }
    }

    std::cout << res << '\n';
}