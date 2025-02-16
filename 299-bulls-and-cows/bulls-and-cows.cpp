class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
    unordered_map<char, int> s_count, g_count;

    for (int i = 0; i < secret.size(); i++) {
        if (secret[i] == guess[i]) {
            bulls++;
        } else {
            s_count[secret[i]]++;
            g_count[guess[i]]++;
        }
    }

    for (auto &[digit, count] : g_count) {
        if (s_count.count(digit)) {
            cows += min(count, s_count[digit]);
        }
    }

    return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};