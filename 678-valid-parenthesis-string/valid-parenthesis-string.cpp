class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0, maxx = 0;
        for(auto it:s){
            if(it == '('){
                mini++;
                maxx++;
            }
            else if(it == ')'){
                mini--;
                maxx--;
            }
            else{
                mini--;
                maxx++;
            }
            if(mini < 0) mini = 0;
            if(maxx < 0) return false;
        }
        return (mini == 0);
    }
};