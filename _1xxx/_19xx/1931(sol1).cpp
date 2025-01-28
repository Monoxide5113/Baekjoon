#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using Meeting = std::pair<int, int>;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<Meeting> meetings(n);
    for (auto& [start, end] : meetings)
        std::cin >> start >> end;
    
    std::sort(meetings.begin(), meetings.end(), [](auto a, auto b) {
        return a.second != b.second ? a.second < b.second : a.first < b.first;
    });

    int res = 1, last_meeting_end = meetings[0].second;
    for (auto it = meetings.cbegin() + 1; it != meetings.cend(); ++it) {
        const auto [start, end] = *it;
        if (start < last_meeting_end) continue;
        last_meeting_end = end;
        ++res;
    }

    std::cout << res << '\n';

    return 0;
}