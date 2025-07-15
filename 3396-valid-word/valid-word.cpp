class Solution {
    bool isvow(char A){
        A = tolower(A);
        return (A == 'a'||A == 'e'||A == 'i'||A == 'o'||A == 'u');
    }
public:
    bool isValid(string word) {
        int c1 = 0, c2 = 0;

        if(word.size() < 3) return false;
        for(auto &it: word){
            if(isalnum(it)) {
                if(isvow(it)) c1++;
                else if(!isdigit(it)) c2++;
            }
            else return false;
        }
        return (c1>0 && c2>0);
    }
};