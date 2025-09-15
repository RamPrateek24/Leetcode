class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char> s;
        for(auto &it: brokenLetters){
            s.insert(it);
        }
        stringstream ss(text);
        string word;
        vector<string> v;
        while(ss >> word){
            v.push_back(word);
        }
        int count = 0;
        for( auto it: v){
            bool f = true;
            for(auto i: it){
                if(s.find(i) != s.end()){
                    f = false;
                    break;
                }
            }
            if(f) count++;
        }
        return count;
    }
};