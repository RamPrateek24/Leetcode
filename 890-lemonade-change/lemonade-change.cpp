class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(auto it:bills){
            if(it == 5) five++;
            else if(it == 10){
                if(five){
                    five -= 1;
                    ten += 1;
                }
                else return false;
            }
            else{
                if(ten && five){
                    ten -= 1;
                    five -= 1;
                }
                else if(five >=3){
                    five -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};