class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for (auto e : A) {
            sum += e;
        }

        if (sum % 3 != 0)
            return false;
        
       int sum3 = sum / 3;
       sum = 0;
       int count = 0;
       for (int i = 0; i < A.size(); i ++) {
           sum += A[i];
           if (sum == sum3) {
               sum = 0;
               count ++;
               if (count == 2 && i != A.size() - 1)
                   return true;
           }
        }

       return false;
    }
};

