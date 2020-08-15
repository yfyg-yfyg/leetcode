class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ans(A.size(), false);

        int rest = A[0] % 5;
        ans[0] = rest == 0;

        for (int i = 1; i < A.size(); i ++) {
            rest = (rest * 2 + A[i]) % 5;
            ans[i] = rest == 0;
        }
 
        return ans;
    }
};

