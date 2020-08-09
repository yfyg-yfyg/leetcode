class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int>  ans(queries.size(), 0);

        int sum = 0;
        for (int i = 0; i < A.size(); i ++) {
            if (A[i] % 2 == 0) 
                sum += A[i];
        } 

        for (int i = 0; i < queries.size(); i ++) {
            int val = queries[i][0];
            int index = queries[i][1];

            if (A[index] % 2 != 0 && val % 2 != 0) {
                sum = sum + A[index] + val;
            }
            else if (A[index] % 2 == 0 && val % 2 != 0) {
                sum = sum - A[index];
            }
            else if (A[index] % 2 == 0 && val % 2 == 0) {
                sum = sum + val;
            }

            A[index] += val;
            ans[i] = sum;
         }

        return ans;
    }
};

