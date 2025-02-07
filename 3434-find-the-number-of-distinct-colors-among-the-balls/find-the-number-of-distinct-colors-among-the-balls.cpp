class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColors;
        unordered_set<int> distinctColors;
        vector<int> result;

        for (const auto& query : queries) {
            int ball = query[0], color = query[1];

            if (ballColors.count(ball)) {
                int oldColor = ballColors[ball];
                bool stillExists = false;
                for (const auto& [b, c] : ballColors) {
                    if (c == oldColor && b != ball) {
                        stillExists = true;
                        break;
                    }
                }
                if (!stillExists) {
                    distinctColors.erase(oldColor);
                }
            }

            ballColors[ball] = color;
            distinctColors.insert(color);
            result.push_back(distinctColors.size());
        }

        return result; 
    }
};