class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5 = 0, count10 = 0;

        for(int i = 0; i < bills.size(); i ++) {
            if (bills[i] == 5) {
                count5 ++; 
                continue;
            }

            if (bills[i] == 10) {
                if (count5 == 0)
                   return false;
                else {
                    count5 --;
                    count10 ++;
                }
            }

            if (bills[i] == 20) {
                if (count5 > 0 && count10 > 0 ) {
                    count10 --;
                    count5 --;
                }
                else if (count5 >=3 ){
                    count5 -= 3;
                }
                else {
                    return false;
                }
            }
        } 
        return true;
    }
};
