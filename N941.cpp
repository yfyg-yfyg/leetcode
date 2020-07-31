class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        bool  decreasing = false;

        if (A.size() < 3)
            return false;

        if (A[1] <= A[0])
            return false;

        int i = 2;
        for (; i < A.size(); i ++ ) {
            if (A[i] == A[i - 1])
                return false;
            else if (A[i] < A[i - 1]) {
                decreasing = true;
                break;
            }
        }

        if (i == A.size()) {
            return false;
        }
        if (i == A.size() - 1 )
            return true;
        else {
            for (i = i + 1; i < A.size(); i ++) {
                if (A[i] >= A[i -1])
                    return false;
            }
        }

        return true;
    }
};

