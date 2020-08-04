class Solution {
    set<int> num_set;
public:
    int repeatedNTimes(vector<int>& A) {
        int ans = 0;
        for (int i = 0; i < A.size(); i ++) {
            if (num_set.count(A[i]) == 1) {
                ans = A[i];
                break;
            }
            else {
                num_set.insert(A[i]);
            }
        }

        return ans;
    }
};

