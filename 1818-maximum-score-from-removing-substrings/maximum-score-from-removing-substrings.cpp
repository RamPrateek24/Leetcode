class Solution {
public:
    int subs(string &s, char first, char sec, int score){
        string temp = "";
        int res = 0;
        for(auto &ch: s){
            if(!temp.empty() && temp.back() == first && ch == sec){
                temp.pop_back();
                res += score;
            }
            else{
                temp += ch;
            }
        }
        s = temp;
        return res;
    }
    int maximumGain(string s, int x, int y) {
        int tot = 0;
        if(x > y){
            tot += subs(s, 'a', 'b', x);
            tot += subs(s, 'b', 'a', y); 
        }
        else{
            tot += subs(s, 'b', 'a', y);
            tot += subs(s, 'a', 'b', x);
        }
        return tot;
    }
};