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
        for (const auto& val : str_num) {
            const int digit = val - ZERO_CHAR;
            if (!digit) return false;
            if (used[digit]) return false;
            used.set(digit);
        }
        return true;
    };

    std::bitset<MAX> answers;
    for (int num = MIN; num < MAX; ++num)
        answers.set(num, is_valid(num));

    int n;
    std::cin >> n;

    auto is_matched = [](int question, int answer, int strike, int ball) {
        int cur_strike = 0, cur_ball = 0;
        const auto str_question = std::to_string(question), str_answer = std::to_string(answer);
        for (int i = 0; i < DIGIT; ++i) {
            if (str_answer.find(str_question[i]) == std::string::npos) continue;
            (str_question[i] == str_answer[i]) ? ++cur_strike : ++cur_ball;
        }
        return cur_strike == strike && cur_ball == ball;
    };

    for (int qry = 0; qry < n; ++qry) {
        int question, strike, ball;
        std::cin >> question >> strike >> ball;

        for (int answer = MIN; answer < MAX; ++answer) {
            if (!answers[answer]) continue;
            if (is_matched(question, answer, strike, ball)) continue;
            answers.reset(answer);
        }
    }

    const int res = answers.count();
    std::cout << res << '\n';

    return 0;
}