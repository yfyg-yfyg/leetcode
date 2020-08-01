class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int count = 0;
        int width = A[0].length();
        for (int i = 0; i < width; i ++) {
            for (int j = 0; j < A.size() - 1; j ++) {
                if (A[j][i] > A[j + 1][i]) {
                    count ++;
                    break;
                }
            }
        }

        return count;
    }
};

