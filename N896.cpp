class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool ans = true;

        int i = 0; 
        for (; i < A.size() - 1; i ++) {
            if (A[i] != A[i + 1]) 
                break;
        }

        if (i == A.size() - 1)
            return true;

        bool asending = true;
        if (A[i] > A[i+1]) 
            asending = false; 

        for ( i = i + 1; i < A.size() - 1; i ++) {
            if (A[i] > A[i+1] && asending || A[i] < A[i+1] && !asending)
                return false;
        }
   
        return ans;
    }
};


class Solution {

    private :
    bool increasing(vector<int> &A) {
        for (int i = 0; i < A.size() - 1; i ++) {
            if (A[i] > A[i + 1])
                return false;
        }

        return true;
    }

    bool decreasing(vector<int> &A) {
        for (int i = 0; i < A.size() - 1; i ++) {
            if (A[i] < A[i + 1])
                return false;
        }

        return true;
    }
public:
    bool isMonotonic(vector<int>& A) {

        return decreasing(A) || increasing(A);
    }
};
