class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());

        int max_perimeter = 0;

        for (int i = A.size() - 3; i >=0; i --) {
            if (A[i] + A[i + 1] > A[i + 2]) {
                max_perimeter = A[i] + A[i + 1] + A[i+2];
                break;
            }
                
        }

        return max_perimeter;
    }
};
