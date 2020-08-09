class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
       vector<int>  ans(A.size(), 0);

       int i = 0;
       for (; i < A.size(); i ++) {
           if (A[i] >= 0) 
               break;
       }

       int k = 0;
       int j = i - 1;
       while (i < A.size() && j >= 0) {
           if (A[i] * A[i] <= A[j] * A[j])  {
               ans[k++] = (A[i] * A[i]);
               i ++;
           }
           else {
               ans[k++] = (A[j] * A[j]);
               j --;
           }
       }

       if (j >= 0) {
           for (; j >= 0; j --) {
               ans[k++] = (A[j] * A[j]);
           }
       }
       
       else if (i < A.size()) {
           for (; i < A.size(); i ++) {
               ans[k++] = (A[i] * A[i]);
           }
       }

       return ans;
    }

};

