#include <array>
#include <bitset>
#include <iostream>
#include <string>

constexpr int MIN = 100, MAX = 1'000;
constexpr int DIGIT = 3;
constexpr int DIGIT_CNT = 10;
constexpr char ZERO_CHAR = '0';

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto is_valid = [](int num) {
        const auto str_num = std::to_string(num);
        std::bitset<DIGIT_CNT> used;
        for (const auto val : str_num) {
            const int digit = val - ZERO_CHAR;
            if (digit == 0) return false;
            if (used[digit]) return false;
            used.set(digit);
        }
        return true;
    };

    std::bitset<MAX> possible_answers;
    for (int num = MIN; num < MAX; ++num)
        possible_answers.set(num, is_valid(num));

    int n;
    std::cin >> n;

    auto is_matched = [](int question, int answer, int strike, int ball) {
        int cur_strike = 0, cur_ball = 0;
        const auto str_question = std::to_string(question), str_answer = std::to_string(answer);
        std::array<int, DIGIT_CNT> digit_pos;
        digit_pos.fill(-1);
        for (int i = 0; i < DIGIT; ++i) {
            const int digit = str_question[i] - ZERO_CHAR;
            digit_pos[digit] = i;
        }
        for (int i = 0; i < DIGIT; ++i) {
            const int digit = str_answer[i] - ZERO_CHAR;
            const int pos = digit_pos[digit];
            if (pos == -1) continue;
            (i == pos) ? ++cur_strike : ++cur_ball;
        }
        return strike == cur_strike && ball == cur_ball;
    };

    for (int qry = 0; qry < n; ++qry) {
        int question, strike, ball;
        std::cin >> question >> strike >> ball;

        for (int answer = MIN; answer < MAX; ++answer) {
            if (!possible_answers[answer]) continue;
            if (is_matched(question, answer, strike, ball)) continue;
            possible_answers.reset(answer);
        }
    }

    const int res = possible_answers.count();
    std::cout << res << '\n';

    return 0;
}