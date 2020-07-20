class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {

        int max_num = A[0], min_num = A[0];

        for(int i = 0; i < A.size(); i ++) {
            max_num = max(max_num, A[i]);
            min_num = min(min_num, A[i]);
        }

        return max(0, max_num - min_num - 2*K);
    }
};


